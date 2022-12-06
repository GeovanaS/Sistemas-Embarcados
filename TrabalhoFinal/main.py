from flask import Flask, render_template

from gpiozero import LED
from time import sleep


app = Flask(__name__)

@app.route("/")
def main():
    print("led desligado")
    red.off()
    return render_template("led-desligado.html")  

@app.route('/led-ligado/')
def ligar_led():
    print ('I got clicked!, led ON')
    red.on()
    return render_template("led-ligado.html")

@app.route('/led-desligado/')
def desligar_led():
    print ('I got clicked!, led OFF')
    red.off()
    return render_template("led-desligado.html")

if __name__ == "__main__":
    
    red = LED(17)

    app.run(debug=True)


#rsync -avz -e ssh --delete Rasp-Teste/ pi@raspberrypi.local:trab-se/

#ssh pi@raspberrypi.local -L 5000:localhost:5000