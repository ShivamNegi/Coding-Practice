counter = 1
for test_cases in range(int(raw_input())):
    m, n, q = map(int, raw_input().split())

    team_a = map(str, range(1, m + 1))
    team_b = map(str, range(m + 1, m + n + 1))
    teams = [team_a, team_b]

    queries = raw_input().split()

    charac_team = ['A', 'B']
    serve = True
    was_serve = False
    team_serving = 0
    curr_team = 0
    Wrong_serv = False
    same_team_counter = 0
    prev_player = 0
    score = [0, 0]
    # print queries
    # print serve, team_serving, score, curr_team
    for ch in queries:
        if serve:
            if ch == 'A' or ch == 'B' or ch == 'X':
                Wrong_serv = True
                break
            else:
                serve = False
                was_serve = True
                curr_team = team_serving
                if ch in teams[team_serving]:
                    same_team_counter = 0
                    prev_player = ch
                else:
                    Wrong_serv = True
                    break
        else:
            if ch == 'A' or ch == 'B':
                if ch == charac_team[team_serving]:
                    serve = True
                    was_serve = False
                    team_serving = 1 - team_serving
                else:
                    serve = True
                    was_serve = False
                    score[team_serving] += 1
            elif ch == 'X':
                if prev_player in teams[team_serving]:
                    serve = True
                    was_serve = False
                    team_serving = 1 - team_serving
                else:
                    serve = True
                    was_serve = False
                    score[team_serving] += 1
            else:
                if was_serve:
                    if ch in teams[team_serving]:
                        serve = True
                        was_serve = False
                        team_serving = 1 - team_serving
                    else:
                        was_serve = False
                        prev_player = ch
                        curr_team = 1 - curr_team
                else:
                    if ch in teams[curr_team]:
                        if ch == prev_player or same_team_counter == 4:
                            ch = charac_team[curr_team]
                            if ch == 'A' or ch == 'B':
                                if ch == charac_team[team_serving]:
                                    serve = True
                                    team_serving = 1 - team_serving
                                else:
                                    serve = True
                                    score[team_serving] += 1
                        else:
                            same_team_counter += 1
                            prev_player = ch
                    else:
                        curr_team = 1 - curr_team
                        prev_player = ch
        # print serve, team_serving, score, ch, curr_team
    # print serve, team_serving, score, ch
    print "Data Set " + `counter` + ":"
    if Wrong_serv:
        print "Wrong Serve"
    else:
        print score[0], score[1]
    counter += 1
    # print score[0], score[1]