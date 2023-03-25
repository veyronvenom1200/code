class hello:
	id = 1
	def __init__(self, name, number):
		self.name = name;
		self.number = number;

	def nameChange(self):
		self.name = self.name + "yes"
	@classmethod
	def hello(cls):
		print("the class method")

nathan = hello("Nathan", 1234567890)
nathan.name = nathan.name + " Dohm"
nathan.nameChange()
print(nathan.name)