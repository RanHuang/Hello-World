# Look up the context in the sessions
>>> import pickle
>>> import base64
>>> base64.b64decode(open(sessions/dd1fd6b79e7d94ba0a890f99311bc4fd67792892).read())
"(dp1\nS'count'\np2\nI18\nsS'ip'\np3\nV113.200.58.73\np4\nsS'session_id'\np5\nS'dd1fd6b79e7d94ba0a890f99311bc4fd67792892'\np6\ns."
>>> x = base64.b64decode(open(sessions/dd1fd6b79e7d94ba0a890f99311bc4fd67792892).read())
>>> pickle.loads(x)
{'count': 18, 'ip': u'113.200.58.73', 'session_id': 'dd1fd6b79e7d94ba0a890f99311bc4fd67792892'}

# Run the game
$python bin/app.py
# Before run the script, set the python path
$export PYTHONPATH=$PYTHONPATH:.
