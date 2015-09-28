from sys import exit
from random import randint

class Scene(object):

    def enter(self):
        print "This class is not yet configured. Subclass it and impleent enter()."
        exit(1)

class Engine(object):

    def __init__(self, scene_map):
        self.scene_map = scene_map

    def play(self):
        current_scene = self.scene_map.opening_scene()

        while True:
            print "\n----------"
            next_scene_name = current_scene.enter()
            current_scene = self.scene_map.next_scene(next_scene_name)

class Death(Scene):

    quips = [
            "You died. You kinda suck at this.",
            "Your mom would be prouud... if she were smater.",
            "Such a luser.",
            "I have a small puppy that's better at this."
            ]

    def enter(self):
        print Death.quips[randint(0, len(self.quips) - 1)]
        exit(1)

class CentralCorridor(Scene):

  def enter(self):
    print "The Gothons of Planet Percal #25 have invaded your ship and destroyed"
    print "your entire crew. You are the last surviving member and your last"
    print "mission is to get the neutron destruct bomb from the Weapons Armory,"
    print "put it in the bridge, and blow the ship up after getting into an "
    print "escape pod."
    print "\n"
    print "You're running down the central corridor to the Weapons Armory when"
    print "a Gothon jumps out, red scaly skin, dark grimy teeth, and evil clown costume"
    print "flowing around his hate filled body. He's blocking the door to the"
    print "Armory and about to pull a weapon to blast you."

    action = raw_input('> ')

    if action == "shoot!":
      print "Quick on the draw you yank out your blaster and fire it at"
      print "the Gothon. His clown costume is flowing and moving around"
      print "his body, which throws off your aim. Your laser hits his "
      print "costume but misses him entirely. This completely ruins his"
      print "brand new costume his mother bought him, which makes him"
      print "fly into a rage and blast you repeatedly in the face until"
      print "you are dead. The he eats you."

      return 'death'

    elif action == "dodge!":

      return 'death'

    elif action == "tell a joke":

      return 'laser_weapon_armory'

    else:
      print "DOES NOT COMPUTE!"
      return 'central_corridor'

class LaserWeaponArmory(Scene):

    def enter(self):
      print "You do a dive roll into the weapon Armory, crouch and scan the room"
      print "for more Gothons that might be hiding. It's dead quiet, too quiet."
      print "You stand up and run to the far side of the room and find the neutron bomb in its container."
      print "There's a keypad lock on the box and you need the code to get the bomb out."
      print "If you get the code wrong 10 times then the lock closes forever and you can't get the bomb."
      print "The code is 3 digits."

      code = "%d%d%d" % (randint(1, 9), randint(1, 9), randint(1, 9))
      guess = raw_input("[keypad]> ")
      guesses = 0
      #just for debug
      print "$#$ Code: %s" % code
        
      while guess != code and guesses < 10:
        print "BZZZZEDDD"
        guesses += 1
        guess = raw_input("[keypad]> ")

      if guess == code:
        print "The container clicks open and the seal breaks, letting gas out."
        print "You grab the neutron bomb and run as fast as you can to the"
        print "bridge where you must place it in the right spot."
        return 'the_bridge'
      else:
        print "The lock buzzes one last time and then you hear a sickening melting sound as the mechanism is fused together."
        print "You decide to sit there, and finally the Gothons blow up the ship from their ship and you die."
        return 'death'

class TheBridge(Scene):

  def enter(self):
    print "You burst onto the Bridge with the neutron destruct bomb under your arm and"
    print "surprise 5 Gothons who are trying to take control of the ship."
    print "Each of them has an even uglier clown costume than the last."
    print "They haven't pulled their weapons out yet, as they see the active bomb under your arm and don't want to see it off."
    action = raw_input("> ")

    if action == "throw the bomb":
      print "In a panic you throw the bomb at the group of Gothons and make a leap fo the door."
      print "Right as you drop it a Gothon shoots you right in the back killing you."
      print "As you die you see another Gothon frantically try to disarm the bomb. You die knowing they will probably blow up when it goes off."
      print 'death'

    elif action =="slowly place the bomb":
      print "You point your blaster at the bomb uner your arm and the Gothons put their hands up and start to sweat."
      print "You inch backward to the door, open it, and then cafully place the bomb on the floor, pointing your blaster at it."
      print "You then jump back through the door, punch the close button and blast the lock so the Gothons can't get out."
      print "Now that the bomb is placed you run to the escape pod ot get off this tin can."
      return 'escape_pod'
    else:
      print "DOES NOT COMPUTE!"
      return "the_bridge"


class EscapePod(Scene):

  def enter(self):
    print "You rush through the ship desperately trying to make it to the escape pod before the whole sheep explodes." 
    print "It seems like hardly and Gothons are on the ship, so your run is clear of interference."
    print "You get to the chamber with the escape pods, and now need to pick one to take."
    print "Some of them could be damaged but you don't have time to look."
    print "There's 5 pods, which one do you take?"

    good_pod = randint(1, 5)
    guess = raw_input("[pod #]> ")

    if int(guess) != good_pod:
      print "You jumb int pod %s and hit the eject button." % guess
      print "The pod escapes out into the void of space, then implodes as the hull reptures, crushing your body int the jam jelly."
      return 'death'
    else:
      print "You jumb into pod %S and hit the eject button" % guess
      print "The pod easily slides out into space heading to the planet below."
      print "As it flies to the planet, you look back and see tyour ship implode the explode like a bright star, "
      print "taking out the Gothon ship at the same tiem. You won!"
      return 'finished'

class Map(object):
  
  scenes = {
          'central_corridor': CentralCorridor(),
          'laser_weapon_armory': LaserWeaponArmory(),
          'the_bridge': TheBridge(),
          'escape_pod': EscapePod(),
          'death': Death()
          }

  def __init__(self, start_scene):
    self.start_scene = start_scene

  def next_scene(self, scene_name):
    return Map.scenes.get(scene_name)

  def opening_scene(self):
    return self.next_scene(self.start_scene)  

a_map = Map('central_corridor')
a_game = Engine(a_map)
a_game.play()
