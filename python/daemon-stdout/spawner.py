import tempfile
import time
import subprocess

_stdout_fd, _stdout = tempfile.mkstemp()
_stderr_fd, _stderr = tempfile.mkstemp()

print("STDOUT_FD: " + str(_stdout_fd))
print("STDOUT: " + _stdout)
print("STDERR FD: " + str(_stderr_fd))
print("STDERR: " + _stderr)

print("Starting")
#daemon = subprocess.Popen(["python", "-u", "daemon.py"], stdout=_stdout_fd, stderr=_stderr_fd)
daemon = subprocess.Popen(["python", "daemon.py"], stdout=_stdout_fd, stderr=_stderr_fd)

time.sleep(20)

print("File contents before terminate:")
print("STDOUT: " + open(_stdout).read())
print("STDERR: " + open(_stderr).read())
print("Terminating daemon")
daemon.terminate()
daemon.wait()

print("\nFile contents after terminate:")
print("STDOUT: " + open(_stdout).read())
print("STDERR: " + open(_stderr).read())
