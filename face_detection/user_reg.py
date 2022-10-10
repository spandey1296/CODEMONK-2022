import face_recognition
import cv2
import json
import numpy as np
def img_resize(path):
    img = cv2.imread(path)
    (h, w) = img.shape[:2]
    width = 500
    ratio = width / float(w)
    height = int(h * ratio)
    # resizing the image with custom width and height

    return cv2.resize(img, (width, height))

def reg_user(userid,password,path):
    with open("sample2.json", "r") as file:
        data = json.loads(file.read())
    getValues = lambda userid, data: [1 for i in range(len(data)) if userid in data[i][0].keys() ]
    valid_user=getValues(userid, data["ids"])

    if valid_user :
        print("Account already exists")
    else:
        if len(password)<6:
            print("password should have 6 or more charcters")
        else:
                img = img_resize(path)

                user_face_det = {
                "ids": {userid: {
                    "password": password,
                    "encoding": list(face_recognition.face_encodings(img)[0])
                }}}

                data["ids"].append([dict(user_face_det["ids"])])
                json_object = json.dumps(data)
                with open("sample2.json", "w") as outfile:
                    outfile.write(json_object)
                    print("JSON updated")



    '''json_object = json.dumps(user_face_det)
    with open("sample2.json", "w") as outfile:
          outfile.write(json_object)'''




def login_userid(userid,password):
    with open("sample2.json", "r") as file:
        data = json.loads(file.read())
    getValues = lambda userid, data: [ i for i in range(len(data)) if userid in data[i][0].keys() ]
    valid_user=getValues(userid, data["ids"])
    if len(valid_user):
        if(password==str(data["ids"][valid_user[0]][0][userid]["password"])):
            print("login successfull")
            return userid

    return -1

def login_userid(path):
            with open("sample2.json", "r") as file:
                data = json.loads(file.read())

            img_login = img_resize(path)
            facesCurFrame_login = face_recognition.face_locations(img_login)

            for i in range(len(data["ids"])): # iterating the list of records
                for j in data["ids"][i][0]: # for accessing each userid
                    matches_login = face_recognition.compare_faces(np.array(data["ids"][i][0][j]["encoding"]),face_recognition.face_encodings(img_login,facesCurFrame_login))
                    faceDis_login = face_recognition.face_distance(np.array(data["ids"][i][0][j]["encoding"]),face_recognition.face_encodings(img_login,facesCurFrame_login))
                    # print(faceDis)
                    matchIndex_login = np.argmin(faceDis_login)
                    if matches_login[matchIndex_login]:
                        return j # userid is returned here

            return -1





