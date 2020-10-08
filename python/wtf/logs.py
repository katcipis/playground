import logging

log = logging.getLogger("wtf")
log.setLevel(logging.DEBUG)

log.debug("debug")
log.info("info")
log.warning("warning")

# Wont work because...why simple if it can be complicated ?
# https://docs.python.org/3/howto/logging.html#logging-advanced-tutorial
# https://stackoverflow.com/questions/57742985/setting-log-level-to-logging-debug-or-logging-info-has-no-effect
