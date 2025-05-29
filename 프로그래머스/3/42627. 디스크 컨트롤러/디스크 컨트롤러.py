import heapq

def solution(jobs):
    jobs = sorted(jobs)  # job 도착 순서로 정렬
    hq = []
    all_time = []
    
    time = 0
    end = -1
    idx = 0  # jobs에서 처리한 인덱스

    while idx < len(jobs) or hq:
        # 현재 시점에 도착한 job을 hq에 추가
        while idx < len(jobs) and jobs[idx][0] <= time:
            st, cst = jobs[idx]
            heapq.heappush(hq, (cst, st))
            idx += 1
        
        if end <= time:
            if hq:
                cost, start = heapq.heappop(hq)
                time += cost
                all_time.append(time - start)
                end = time
            else:
                # 처리할 job이 없으면 다음 job 도착 시점으로 점프
                if idx < len(jobs):
                    time = jobs[idx][0]
        else:
            time = end  # 현재 실행 중인 작업 종료 시점으로 점프
    
    return sum(all_time) // len(all_time)
