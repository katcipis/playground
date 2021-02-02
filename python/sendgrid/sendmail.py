import os
import sys

from sendgrid import SendGridAPIClient
from sendgrid.helpers.mail import Mail

from_email=sys.argv[1]
to_email=sys.argv[2]
contents_path=sys.argv[3]

with open(contents_path) as f:
    contents = f.read()

message = Mail(
    from_email=from_email,
    to_emails=to_email,
    subject='Sending with Twilio SendGrid is Fun',
    html_content=contents)

sg = SendGridAPIClient(os.environ.get('SENDGRID_API_KEY'))
response = sg.send(message)
print(response.status_code)
print(response.body)
print(response.headers)
