import sqlite3

class Database:
    def __init__(self, file):
        self.conn = sqlite3.connect('file')
	self.curs = self.conn.cursor()
    def close(self):
        self.conn.close()
    def getlength(self, type):
        return 1
    def getLength(self, type):
        return 1
    def query(self, q, type):
        return 1
