hit = 0;
time = 0;
cache = []

with open("input.txt",'r') as f:
    f_line=f.readline()
    f_list=f_line.split() #파일에서 읽어온 값들 저장된 리스트

for i in f_list: #블록번호 리스트 전체 돌면서
    if i == '99': break #99만나면 끝
    time += 1 #한 번 돌 때마다 time 1씩 추가
    
    if len(cache) < 3 and i not in [j[0] for j in cache]: #캐시가 꽉 차지도 않고 hit도 안됨
        cache.append([i,time])
        continue
    elif i in [j[0] for j in cache]: #hit
        index = [j[0] for j in cache].index(i)
        cache[index] = [i,time]
        hit += 1
    else: #캐시가 꽉 차고, hit되지 않음 -> 교체
        countList = [j[1] for j in cache] #count만 모아둔 리스트
        index = countList.index(min(countList)) #count가 제일 작은 index구하기
        cache[index] = [i,time] #구한 위치로 교체

print([b[0] for b in cache])
print("hit ratio: %d/%d"%(hit,time))