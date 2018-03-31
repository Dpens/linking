from flask import Flask,render_template,request
import mysql.connector

app = Flask(__name__)

conn = mysql.connector.connect(user='root',password='Password',database='userchar')
cursor = conn.cursor()
cursor.execute('create table if not exists \
	userdb(id INT UNSIGNED NOT NULL PRIMARY KEY AUTO_INCREMENT,username VARCHAR(20),password varchar(20))AUTO_INCREMENT = 0')
#cursor.execute('insert into userdb (id,username,password) values(%s,%s,%s)',['NULL','Dpens','123'])
#conn.commit()
#cursor.close()


@app.route('/')
def hello(name='Dpens'):
    return render_template('hello.html', name=name)

@app.route('/',methods=['GET','POST'])
def index():
	if request.method == 'POST':
		xusername = request.form.get("username")
		xpassword = request.form.get("psw")
		xid = '0'
		cursor.execute('insert into userdb (id,username,password) values("%s","%s","%s")'%(xid,xusername,xpassword))
		conn.commit()
		cursor.close()
		return render_template('sign_in.html')

if __name__ == '__main__':
	app.run(debug = True)

conn.close()