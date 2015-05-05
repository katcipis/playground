import tempfile
import time
import subprocess

_stdout = tempfile.TemporaryFile()
_stderr = tempfile.TemporaryFile()

print("Starting")
daemon = subprocess.Popen(["python", "daemon.py"], stdout=_stdout, stderr=_stderr)

time.sleep(5)
print("Terminating daemon")
daemon.terminate()
daemon.wait()

print("STDOUT: " + _stdout.read())
print("STDERR: " + _stderr.read())
