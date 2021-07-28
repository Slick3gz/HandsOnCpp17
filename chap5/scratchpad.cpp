#define KILL

#include <unistd.h>
#include <iostream>

/**********************************************************/
#ifdef LOOP
auto loop = true;
#endif
/**********************************************************/

/**********************************************************/
#ifdef SIGNALS
#include <signal.h>

void
handler (int sig)
{
	if (sig == SIGINT)
	{
		std::cout << "handler called.\n";
#ifdef LOOP
		loop = false;
#endif
	}
}
#endif
/**********************************************************/

/**********************************************************/
#ifdef REDIRECT
#include <sys/wait.h>

#include <array>
#include <iostream>
#include <string_view>

class mypipe
{
	std::array<int, 2> m_handles;

public:
	mypipe()
	{
		if (pipe(m_handles.data()) < 0) {
			exit(1);
		}
	}

	~mypipe()
	{
		close(m_handles.at(0));
		close(m_handles.at(1));
	}

	std::string
	read()
	{
		std::array<char, 256> buf;
		std::size_t bytes = ::read(m_handles.at(0), buf.data(), buf.size());

		if (bytes > 0)
		{
			return {buf.data(), bytes};
		}
		return {};
	}

	void
	redirect()
	{
		dup2(m_handles.at(1), STDOUT_FILENO);
		close(m_handles.at(0));
		close(m_handles.at(1));
	}
};
#endif
/**********************************************************/

/**********************************************************/
#ifdef SYSCALL
#include <sys/wait.h>

void
mysystem(const char *command)
{
	if (fork() == 0) {
		execlp(command, command, nullptr);
	}
	else {
		wait(nullptr);
	}
}
#endif
/**********************************************************/

/**********************************************************/
#ifdef KILL 
#include <sys/wait.h>
#include <signal.h>

void
mysystem(const char *command)
{
	if (auto id = fork(); id > 0) {
		sleep(2);
		kill(id, SIGINT);
	}
	else {
		execlp(command, command, nullptr);
	}
}
#endif
/**********************************************************/

int main(void){

/**********************************************************/
#ifdef FORK
	auto id1 = fork();
	std::cout << "id1: " << id1 << '\n';

	auto id2 = fork();
	std::cout << "id1: " << id2 << '\n';
	std::cout << "------------\n";
#endif
/**********************************************************/

/**********************************************************/
#ifdef EXEC
	execl("/bin/ls", "ls", nullptr);
	std::cout << "Hello World\n";

/**********************************************************/
#endif


/**********************************************************/
#ifdef SYSTEM 
	system("ls");
	std::cout << "Hello World\n";
#endif
/**********************************************************/

/**********************************************************/
#ifdef SYSCALL 
	mysystem("ls");
	std::cout << "Hello World\n";
#endif
/**********************************************************/

/**********************************************************/
#ifdef EXECL 
	execl("/bin/ls", "ls", "-al", nullptr);
#endif
/**********************************************************/

/**********************************************************/
#ifdef EXECLE 
	const char *envp[] = {"ENV1=1", "ENV2=2", nullptr};
	execle("/bin/ls", "ls", "-al", nullptr, envp);
#endif
/**********************************************************/

/**********************************************************/
#ifdef EXECLP 
	execlp("ls", "ls", nullptr);
#endif
/**********************************************************/

/**********************************************************/
#ifdef EXECV 
	const char *argv[] = {"ls", nullptr};
	execv("/bin/ls", const_cast<char **>(argv));
#endif
/**********************************************************/

/**********************************************************/
#ifdef EXECVE 
	const char *argv[] = {"ls", nullptr};
	const char *envp[] = {"ENV1=1", "ENV2=2", nullptr};

	execve(
		"/bin/ls", 
		const_cast<char **>(argv),
		const_cast<char **>(envp)
		);
#endif
/**********************************************************/

/**********************************************************/
#ifdef EXECVP 
	const char *argv[] = {"ls", nullptr};
	execvp("/bin/ls", const_cast<char **>(argv));

#endif
/**********************************************************/

/**********************************************************/
#ifdef REDIRECT 
	mypipe p;

	if (fork() == 0) {
		p.redirect();
		execlp("ls", "ls", nullptr);
	}
	else {
		wait(nullptr);
		std::cout << p.read() << '\n';
	}
#endif
/**********************************************************/

/**********************************************************/
#ifdef SIGNALS
	signal(SIGINT, handler);

#ifdef LOOP
	while(loop)
#else
	for (auto i = 0; i < 10; i++)
#endif
	{
		std::cout << "Hello World\n";
		sleep(1);
	}
#endif
/**********************************************************/

/**********************************************************/
#ifdef KILL
	mysystem("top");
#endif
}
