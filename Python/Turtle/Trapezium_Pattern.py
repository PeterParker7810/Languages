import turtle
import random

t = turtle.Turtle()
s = turtle.getscreen()

t.pensize(5)
t.shape("circle")
t.speed(400)
s.bgcolor("black")

colors = ["Yellow","Red","Blue","Green","Brown","Purple","Cyan","Pink"]

while True:
    t.begin_fill()
    choice = random.choice(colors)
    t.color(choice)
    t.fd(120)
    t.rt(60)
    t.fd(120)
    t.rt(60)
    t.fd(120)
    t.rt(30)
    t.end_fill()