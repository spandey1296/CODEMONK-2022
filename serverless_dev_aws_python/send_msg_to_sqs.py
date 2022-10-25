import json
import boto3

sqs_client = boto3.client('sqs')

def lambda_handler(event, context):
    # this will send message to the queue whose url will be provided
    msg = sqs_client.send_message(QueueUrl='<QUEUE URL>',MessageBody=<MESSAGE>,MessageGroupId=<A GROUP ID TO GROUP MESSAGES IN BATCHES>,
        MessageDeduplicationId=<AN ID TO UNIQUELY DISTINGUISE MESSAGES>)
    
    return {
    'statusCode': 200,
    'body': json.dumps('Success!')
    }
