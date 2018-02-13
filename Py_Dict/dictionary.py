# -*- coding: utf-8 -*-
# Ung dung Tra tu dien (Console)
# Le Hong Hai

# Database
database = {
	'control'	: 'dieu khien',
	'address'	: 'dia chi',
	'link'		: 'lien ket',
	'computer'	: 'may tinh',
	'device'	: 'thiet bi',
	'memory'	: 'bo nho',
	'process'	: 'xu ly',
	'data'		: 'du lieu',
	'bandwidth'	: 'bang thong',
	'user'		: 'nguoi dung',
	'admin'		: 'quan tri',
	'port'		: 'cong',
	'packet'	: 'goi'
}

# Menu Select
def show_menu():
	print "------------------------------"
	print "| TU DIEN CHUYEN NGHANH CNTT |"
	print "------------------------------"
	print "| 1. Them 		     |"
	print "| 2. Tra 		     |"
	print "| 3. Xoa 		     |"
	print "| 4. Sua 		     |"
	print "| 5. Xem tat ca 	     |"
	print "| 6. Thoat 		     |"
	print "------------------------------"

# Them
def add():
	print "-----Them tu-----"
	eng = str(raw_input("English: "))
	# Kiem tra xem da co tu trong dict chua
	if eng in database:
			print "Tu nay da ton tai"
	else:
		vie = str(raw_input("Vietnamese: "))
		# add vao data (dict)
		database[eng] = vie
		print "Da them!"

# Tim Kiem
def find():
	print "-----Tim tu-----"
	eng = str(raw_input("Nhap tu can tra: "))
	# Kiem tra neu eng co trong database khong
	if eng in database:
			print "%s : %s" % (eng, database[eng])
	else:
		print "Khong tim thay: '%s'" % eng

# Xoa
def delete():
	print "-----Xoa tu-----"
	eng = str(raw_input("Nhap tu muon xoa (English): "))
	# Kiem tra xem da co tu trong dict chua
	if eng in database:
		del database[eng]
		print "Da xoa '%s'" % eng
	else:
		print "'%s' Khong ton tai" % eng

# Chinh sua
def edit():
	print "-----Sua tu-----"
	eng = str(raw_input("Nhap tu muon sua (English): "))
	# Kiem tra xem da co tu trong dict chua
	if eng in database:
		vie = str(raw_input("Vietnamese: "))
		# add vao data (dict)
		database[eng] = vie
		print "Da sua!"
	else:
		print "'%s' Khong ton tai" % eng

# Hien thi tat ca
def view_all():
	print "-----Xem tat ca-----"
	# Duyet tat ca cac keys va values
	for eng, vie in database.items():
		print "%s : %s" % (eng, vie)

# Hien thi menu
show_menu()

# main
choice = int(input("Chon chuc nang: "))
while choice != 6:
	if choice  == 6:
		break
	elif choice == 1:
		add()
	elif choice == 2:
		find()
	elif choice == 3:
		delete()
	elif choice == 4:
		edit()
	elif choice == 5:
		view_all()
	else:
		print "Khong co chuc nang nay"

	# Tiep tuc yeu cau nguoi dung chon tiep
	choice = int(input("Chon chuc nang: "))

print "Da thoat!"