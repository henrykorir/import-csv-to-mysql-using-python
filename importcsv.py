import sys
import MySQLdb
import csv
import getpass
from datetime import datetime
def main():
	if sys.argv < 4:
		print('To few arguments, please specify a filename')
	file_name=sys.argv[1]
	dbase=sys.argv[2]
	hst=sys.argv[3]
	user1=sys.argv[4]
	print("Password for "+user1+"@"+hst+": ")
	password=getpass.getpass()
#try:
	with open(file_name) as csvfile:
		print("Importing data from "+file_name+" into "+dbase+" database on "+hst+"...")
		reader= csv.DictReader(csvfile)
#except IOError:
		#print("Can't open file " + fileName + ".")
		for row in reader:
			conn = MySQLdb.connect(host=hst, # your host, usually localhost
					user=user1, # your username
					passwd=password, # your password
					db=dbase) # name of the data base
			sql_statement = "INSERT IGNORE INTO routes (route_id,route_name) VALUES (%s,%s)"
			#print(sql_statement)
			cur = conn.cursor()
		
			cur.executemany(sql_statement,[(row['route_id'],row['route_name'])])
			conn.escape_string(sql_statement)
			conn.commit()
		
			sql_statement = "INSERT IGNORE INTO stops (stop_id,stop_name) VALUES (%s,%s)"
			#print(sql_statement)
			cur = conn.cursor()
		
			cur.executemany(sql_statement,[(row['stop_id'],row['stop_name'])])
			conn.escape_string(sql_statement)
			conn.commit()
		
			sql_statement = "INSERT IGNORE INTO vehicles (vehicle_id) VALUES (%s)"
			#print(sql_statement)
			cur = conn.cursor()
		
			cur.executemany(sql_statement,[(row['vehicle_id'])])
			conn.escape_string(sql_statement)
			conn.commit()
		
			sql_statement = "INSERT INTO passenger_data (pdate,route_id,direction,stop_id,on_number,off_number,vehicle_id) VALUES (%s,%s,%s,%s,%s,%s,%s)"
			#print(sql_statement)
			cur = conn.cursor()
		
			cur.executemany(sql_statement,[(datetime.strptime(row['date'], '%m/%d/%Y'),row['route_id'],row['direction'],row['stop_id'],row['ons'],row['offs'],row['vehicle_id'])])
			conn.escape_string(sql_statement)
			conn.commit()
			
			cur.close()
			conn.close()
		print("done")
main()