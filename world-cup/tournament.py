# Simulate a sports tournament

import csv
import sys
import random
import time

# Number of simluations to run
N = [10, 100, 1000, 10000, 100000, 1000000]


def main():
    # Ensure correct usage
    if len(sys.argv) != 2:
        sys.exit("Usage: python tournament.py FILENAME")

    teams = []
    filename = sys.argv[1]

    # TODO: Read teams into memory from file # Append each team's dictionary to the teams list
    with open(filename) as f:
        reader = csv.DictReader(f)
        for row in reader:
            teams.append({"team": row["team"], "rating": int(row["rating"])})

    for n in N:
        # timer
        start_time = time.time()

        counts = {}
        # TODO: Simulate N tournaments and keep track of win counts # Determine the winner of the tournament # Increment the team's win count in the counts dictionary
        for i in range(n):
            winner = simulate_tournament(teams)
            if winner in counts:
                counts[winner] += 1
            else:
                counts[winner] = 1

    # calculated elapsed time
    elapsed_time = time.time() - start_time

    # Print each team's chances of winning, according to simulation
    for team in sorted(counts, key=lambda team: counts[team], reverse=True):
        print(f"{team}: {counts[team] * 10 / n:.1f}% chance of winning")

    # printf time taken
    print(f"Elapsed time: {elapsed_time: .3f}s")
    print()


def simulate_game(team1, team2):
    """Simulate a game. Return True if team1 wins, False otherwise."""
    rating1 = team1["rating"]
    rating2 = team2["rating"]
    probability = 1 / (1 + 10 ** ((rating2 - rating1) / 600))
    return random.random() < probability


def simulate_round(teams):
    """Simulate a round. Return a list of winning teams."""
    winners = []

    # Simulate games for all pairs of teams
    for i in range(0, len(teams), 2):
        if simulate_game(teams[i], teams[i + 1]):
            winners.append(teams[i])
        else:
            winners.append(teams[i + 1])

    return winners


def simulate_tournament(teams):
    """Simulate a tournament. Return name of winning team."""
    # TODO # Simulate rounds until there is only one team left # Return the name of the winning team
    while len(teams) > 1:
        teams = simulate_round(teams)
    return teams[0]["team"]


if __name__ == "__main__":
    main()
