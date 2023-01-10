import logging
import sys
from google.cloud.logging.handlers import StructuredLogHandler

handler = StructuredLogHandler()
logging.getLogger().addHandler(handler)

logging.debug("hi")
logging.info("hi")
logging.warning("hi")
logging.error("hi")
