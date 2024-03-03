
def orientation(p, q, r):
    val = (q[1] - p[1]) * (r[0] - q[0]) - (q[0] - p[0]) * (r[1] - q[1])
    if val == 0:
        return 0
    return 1 if val > 0 else 2

def convex_hull(points):
    n = len(points)
    if n < 3:
        return None
    l = 0
    for i in range(1, n):
        if points[i][0] < points[l][0]:
            l = i
    hull = []
    p = l
    q = 0
    while True:
        hull.append(points[p])
        q = (p + 1) % n
        for i in range(n):
            if orientation(points[p], points[i], points[q]) == 2:
                q = i
        p = q
        if p == l:
            break
    return hull

def generate_random_points(n):
    return [(random.randint(0, 100), random.randint(0, 100)) for _ in range(n)]

def plot_convex_hull(points, convex_hull_points):
    x = [point[0] for point in points]
    y = [point[1] for point in points]
    plt.scatter(x, y, color='blue')
    convex_hull_points.append(convex_hull_points[0])  # Close the loop
    ch_x = [point[0] for point in convex_hull_points]
    ch_y = [point[1] for point in convex_hull_points]
    plt.plot(ch_x, ch_y, color='red')
    plt.xlabel('X')
    plt.ylabel('Y')
    plt.title('Convex Hull Visualization')
    plt.grid(True)
    plt.show()

if __name__ == "__main__":
    points = generate_random_points(20)
    convex_hull_points = convex_hull(points)
    print("Randomly Generated Points:", points)
    print("Convex Hull Points:", convex_hull_points)
    plot_convex_hull(points, convex_hull_points)

