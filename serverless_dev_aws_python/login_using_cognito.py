import json
import os
import boto3

client = boto3.client("cognito-idp", region_name="<YOUR AWS REGION>")

def lambda_handler(event, context):
    data = json.loads(event['body'])
    username = data['username']
    password = data['password']

    # Initiating the Authentication,
    resp = client.initiate_auth(
    ClientId=os.getenv("COGNITO_USER_CLIENT_ID"),
    AuthFlow="USER_PASSWORD_AUTH",
    AuthParameters={"USERNAME": username, "PASSWORD": password},
    )

    return {
    'statusCode': 200,
    'headers': {'Content-Type': 'application/json'},
    'body': json.dumps(message)
    }
