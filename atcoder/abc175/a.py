s = input()

if s in ["RSS", "SRS", "SSR", "RSR"]:
    print(1)
elif s in ["RRS", "SRR"]:
    print(2)
elif s in ["RRR"]:
    print(3)
else:
    print(0)
