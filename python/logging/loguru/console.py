from loguru import logger
import sys


def my_fmt(record):
    elapsed = record["elapsed"]
    level = record["level"]
    message = record["message"]

    msg = f"{elapsed} : {level} : "
    msgparts = []
    for key, val in record["extra"].items():
        msgparts.append(key + "=" + val)

    msgparts.append(message)
    msg += " ".join(msgparts)
    return msg + "\n"


logger.remove()
logger.add(sys.stdout, format=my_fmt, level="INFO", enqueue=False)
context_logger = logger.bind(ip="192.168.0.1", user="someone")


if __name__ == "__main__":
    for _ in range(10):
        context_logger.info("Contextualize your logger easily")
        context_logger.error("ERROR")
