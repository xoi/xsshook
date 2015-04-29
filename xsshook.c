#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <X11/extensions/scrnsaver.h>

int main(int argc, char *argv[])
{
  if (argc < 2)
    exit(EXIT_FAILURE);

  char *command = argv[1];

  Display *display = XOpenDisplay(NULL);
  Window root = DefaultRootWindow(display);

  // not check version

  XScreenSaverSelectInput(display, root, ScreenSaverNotifyMask);

  pid_t pid = -1, w;

  XEvent event;
  for (;;) {
    XNextEvent(display, &event);
    switch (((XScreenSaverNotifyEvent*)&event)->state) {
      case ScreenSaverOn:
	pid = fork();
	if (pid == -1) {
	  perror("fork");
	} else if (pid == 0) {		// child
	  execl("/bin/sh", "sh", "-c", command, (char*)NULL);
	  perror("execl");
	}
	break;
      case ScreenSaverOff:
	if (0 < pid) {
	  kill(pid, SIGTERM);
	  w = wait(NULL);
	  if (w == -1) {
	    perror("wait");
	    exit(EXIT_FAILURE);
	  }
	  pid = -1;
	}
	break;
    }
  }
}
