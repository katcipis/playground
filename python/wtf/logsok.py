import logging

logging.basicConfig()
log = logging.getLogger("wtf")
log.setLevel(logging.DEBUG)

log.debug("debug")
log.info("info")
log.warning("warning")
