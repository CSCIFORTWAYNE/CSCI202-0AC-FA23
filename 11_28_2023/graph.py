import networkx as nx
import matplotlib.pyplot as plt

#G =  nx.random_k_out_graph(12, 2, 25, False)
G = nx.to_directed(nx.read_adjlist("g.txt"))


# explicitly set positions
# pos = {1: (0, 0), 2: (-1, 0.3), 3: (2, 0.17), 4: (4, 0.255), 5: (5, 0.03)}

options = {
    "font_size": 12,
    "node_size": 300,
    "node_color": "white",
    "edgecolors": "black",
    "linewidths": 1,
    "width": 1,
}
nx.draw_networkx(G, **options)

# Set margins for the axes so that nodes aren't clipped

#ax = plt.gca()
#ax.margins(0.20)
plt.axis("off")
plt.show()