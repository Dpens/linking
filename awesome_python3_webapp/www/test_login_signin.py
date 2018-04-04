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


@app.route('/')
def start():
	return render_template('start.html')

@app.route('/register')
def reg():
	return render_template('hello.html')

@app.route('/register', methods=['POST'])
def reg_new():
	xusername = request.form.get("username")
	xpassword = request.form.get("psw")
	cursor.execute('select * from userdb where id > 0')
	results = cursor.fetchall()
	xid = '0'
	for row in results:
		if xusername == row[1]:
			flash('%s already exists'%xusername)
			xid = '1'
	if xid == '0':
		cursor.execute('insert into userdb (id,username,password) values("%s","%s","%s")'%(xid,xusername,xpassword))
		conn.commit()
		return render_template('sign_in.html')
	else:
		return render_template('hello.html', messagebox='error')
	

@app.route('/login')
def log_in():
	return render_template('log_in.html')

@app.route('/login', methods=['POST'])
def log():
		xusername = request.form.get("username")
		xpassword = request.form.get("psw")
		cursor.execute('select * from userdb where id > 0')
		results = cursor.fetchall()
		temp = 0
		for row in results:
			if xusername == row[1] and xpassword == row[2]:
				temp = 1
		if temp == 0:
			flash('username or password is error')
			return render_template('log_in.html', messagebox='error')
		else:
			return render_template('Welcome.html')


if __name__ == '__main__':
	app.run(debug = True)
	
cursor.close()
conn.close()