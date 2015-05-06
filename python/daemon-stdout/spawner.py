import tempfile
import time
import subprocess


def test_this_shit (proc_name):
    print("=== Testing: " + proc_name + " ===")
    _stdout_fd, _stdout = tempfile.mkstemp()
    _stderr_fd, _stderr = tempfile.mkstemp()

    print("STDOUT_FD: " + str(_stdout_fd))
    print("STDOUT: " + _stdout)
    print("STDERR FD: " + str(_stderr_fd))
    print("STDERR: " + _stderr)

    print("Starting")
    #daemon = subprocess.Popen(["python", "-u", "daemon.py"], stdout=_stdout_fd, stderr=_stderr_fd)
    daemon = subprocess.Popen(["python", proc_name], stdout=_stdout_fd, stderr=_stderr_fd)

    time.sleep(5)

    print("Terminating daemon")
    daemon.terminate()
    daemon.wait()

    print("\nProc output")
    print("STDOUT: " + open(_stdout).read())
    print("STDERR: " + open(_stderr).read())
    print("Done Testing: " + proc_name + "\n\n")


test_this_shit("daemon.py")
test_this_shit("command.py")
