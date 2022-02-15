import os, sys
import json
import copy


filename = "TowerAtlas.json"

with open(filename) as json_file:
    data = json.load(json_file)


    data2 = copy.deepcopy(data)

    for i in data["frames"]:
        if "AttackUp " in i["filename"] or "AttackDown " in i["filename"]:
            if "AttackUp " in i["filename"]:
                i["filename"] = i["filename"][:-6] + "Up" + i["filename"][-6:]
            if "AttackDown " in i["filename"]:
                i["filename"] = i["filename"][:-6] + "Down" + i["filename"][-6:]
        if i["rotated"]:
            width = i["frame"]["w"]
            i["frame"]["w"] = i["frame"]["h"]
            i["frame"]["h"] = width
            i["spriteSourceSize"]["y"] += i["spriteSourceSize"]["h"]

    for i in data2["frames"]:
        if "AttackUp " in i["filename"] or "AttackDown " in i["filename"]:
            del i
        else:
            if i["rotated"]:
                i["filename"] = i["filename"][:-11] + "Left" + i["filename"][-6:]
                width = i["frame"]["w"]
                i["frame"]["w"] = i["frame"]["h"]
                i["frame"]["h"] = width
                i["spriteSourceSize"]["x"] = i["sourceSize"]["w"] - i["spriteSourceSize"]["x"] - i["frame"]["w"]
                i["frame"]["x"] = i["frame"]["x"] + i["frame"]["w"]
                i["frame"]["w"] = 0 - i["frame"]["w"]
                i["spriteSourceSize"]["x"] += i["spriteSourceSize"]["h"]
            else:
                i["filename"] = i["filename"][:-11] + "Left" + i["filename"][-6:]
                i["spriteSourceSize"]["x"] = i["sourceSize"]["w"] - i["spriteSourceSize"]["x"] - i["frame"]["w"]
                i["frame"]["x"] = i["frame"]["x"] + i["frame"]["w"]
                i["frame"]["w"] = 0 - i["frame"]["w"]

    data["frames"] = data["frames"] + data2["frames"]

    for i in data["frames"]:
        print(i)

    with open(filename[:-5] + "flipped" + filename[-5:], "w", encoding="utf-8") as f:
        json.dump(data, f, ensure_ascii=False, indent=2)

test = input("est")
