from flask import Flask

server = Flask(__name__)
# in Javascript: var server = new Flask()

@server.route('/')
def test2():
    return 'Hello world!'

@server.route('/more')
def more_stuff():
    return 'This site was developed was a test.'

@server.route('/user/<username>')
def show_user_info(username):
    return "User: " + username

@server.route('/post/<int:post_id>')
def get_post_info(post_id):
    return "Post ID: " + post_id
