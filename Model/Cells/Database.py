import sqlite3

class Database:
    def __init__(self, file):
        self._conn = sqlite3.connect('file')
    def close(self):
        self._conn.close()
    def getlength(self, type):
        return 1
    def getLength(self, type):
        return 1
    def query(self, q, type):
        return 1