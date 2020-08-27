import json as j

with open('auth.json') as spec_file:
    spec1 = j.load(spec_file )
    # js.validate(spec1, schema)

auth_manufact=spec1["serial"]

with open('serial2.json') as spec_file:
    spec2 = j.load(spec_file )
    # js.validate(spec2, schema)
# x = set(auth_manufact) & set(spec2)

for i in spec2["serial"]:
    # print(i)
    if i not in auth_manufact:
        print(i)

# print(spec1.keys())
