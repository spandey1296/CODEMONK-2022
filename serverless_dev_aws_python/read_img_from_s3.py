import base64
import boto3
import json
import random
from PIL import Image
from PIL import ImageDraw
from PIL import ImageFont
import io

s3 = boto3.client('s3')


def lambda_handler(event, context):

    response = s3.get_object(
        Bucket='<BUCKET NAME>',
        Key='<IMAGE NAME>',
    )
    image = response['Body'].read()
    image = Image.open(io.BytesIO(image))

    print(type(image))
    return {
        'statusCode': 200,
    }
