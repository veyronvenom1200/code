import sys
import hashlib

class check_sum:
	def __init__(self, file_name):
		self.file_name = file_name
		self.sha256_hash = self.get_hash()

	# def __repr__(self):
	# 	return "dumbass"

	def get_hash(self):
		sha256_hash_temp = hashlib.sha256()
		with open(self.file_name, "rb") as f:
			for byte_block in iter(lambda: f.read(4096),b""):
				sha256_hash_temp.update(byte_block)
			return sha256_hash_temp.hexdigest()

	def compare(self):
		pass

		# print(check_sum1 == check_sum2)
# file_name = "cdc.py"


file_dict = {}
for i in range(1, len(sys.argv)):
    file_name = sys.argv[i]
    print(file_name)
    file_dict[file_name] = check_sum(sys.argv[i]).sha256_hash
# file1 = check_sum(sys.argv[1]).sha256_hash
# files = sys.argv[1:]
print(__name__)
# file1 = check_sum(sys.argv[1]).get_hash()

# print(file1)