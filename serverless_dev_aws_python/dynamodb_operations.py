import json
import boto3

#importing dynamodb using boto3
dynamodb = boto3.client('dynamodb')

def lambda_handler(event, context):
    #get item query
    dynamodb.get_item(TableName='<your table name>', Key={'<key name>':{'S':'<key value>'}})

    #put item query to put new item in db
    dynamodb.put_item(TableName='<your table name>', Item={'<key name 1>':{'S':'<key value 1>'},'<key name 2>':{'N':'<key value 2>'}})


    table = boto3.resource('dynamodb').Table('table_name')
    #update item query to update an existing record in db
    table.update_item(
        Key={'<key>': '<value>'},
        AttributeUpdates={
            'status': 'completed',
        },
    )


    return {
        'statusCode': 200,
        'body': json.dumps('Hello from Lambda!')
    }
