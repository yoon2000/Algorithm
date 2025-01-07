import sys
from socket import *

HOST = sys.argv[1] # 호스트명 또는 IP 주소
PORT = int(sys.argv[2]) # 포트번호

with socket(AF_INET, SOCK_STREAM) as cs:
    cs.connect((HOST, PORT))
    while True:
        user_input = sys.stdin.readline().rstrip()
        user_input += "\n"
        user_input = user_input.replace('\n', '\r\n')  # 입력받은 라인의 마지막이 "\n"인 경우 "\r\n"으로 변환
        cs.sendall(user_input.encode())  # 서버로 전송
        if user_input == '\r\n' or user_input == '\n':  # 입력받은 라인이 공백라인인 경우
            break

    while True:
        data = cs.recv(1024)  # 서버로부터 전송되는 내용을 1024바이트씩 안정적으로 받기
        if not data:
            break
        print(data.decode('utf-8'), end='')
