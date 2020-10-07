from datetime import datetime
from datetime import timezone
from datetime import date

formatted_timestamp = datetime.now(timezone.utc).isoformat()
timestamp = date.fromisoformat(formatted_timestamp)
