from flask import Flask,render_template,request,flash
import mysql.connector
import tkinter
import tkinter.messagebox
from tkinter import *

app = Flask(__name__)
app.secret_key = 'some_secret'

conn = mysql.connector.connect(user='root',password='Password',database='userchar')
cursor = conn.cursor()
cursor.execute('create table if not exists \
	userdb(id INT UNSIGNED NOT NULL PRIMARY KEY AUTO_INCREMENT,username VARCHAR(20),password varchar(20))AUTO_INCREMENT = 0')
#cursor.execute('insert into userdb (id,username,password) values(%s,%s,%s)',['NULL','Dpens','123'])
#conn.commit()
#cursor.close()


#@app.route('/')
#def hello(name='Dpens'):
    #return render_template('hello.html', name=name)

def turn():
	if request.methods == 'POST':
		if request.form.get("sign in") == 'sign_in':
			return render_template('hello.html')
		elif request.form.get("log in") == 'log_in':
			return render_template('log_in.html')


@app.route('/')
def start():
	return render_template('start.html')
	turn()
	

@app.route('/',methods=['GET','POST'])
def index():
	if request.method == 'POST':
		xusername = request.form.get("username")
		xpassword = request.form.get("psw")
		xid = '0'
		if request.form.get("sign") == '注册':
			cursor.execute('select * from userdb where id > 0')
			results = cursor.fetchall()
			for row in results:
				if xusername == row[1]:
					#tkinter.messagebox.showerror('error','%s already exists'%xusername)
					flash('%s already exists'%xusername)
					xid = '1'
		else:
			return render_template('hello.html')
		if xid == '0':
			cursor.execute('insert into userdb (id,username,password) values("%s","%s","%s")'%(xid,xusername,xpassword))
			conn.commit()
			cursor.close()
			return render_template('sign_in.html')
		return render_template('hello.html')


if __name__ == '__main__':
	app.run(debug = True)

conn.close()