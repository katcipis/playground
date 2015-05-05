import tempfile
import time
import subprocess

_stdout = tempfile.TemporaryFile()
_stderr = tempfile.TemporaryFile()

print("Starting")
daemon = subprocess.Popen(["python", "daemon.py"], stdout=_stdout, stderr=_stderr)

time.sleep(5)

print("File contents before terminate:")
print("STDOUT: " + _stdout.read())
print("STDERR: " + _stderr.read())
print("Terminating daemon")
daemon.terminate()
daemon.wait()

print("\nFile contents after terminate:")
print("STDOUT: " + _stdout.read())
print("STDERR: " + _stderr.read())
