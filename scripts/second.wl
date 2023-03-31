points1 = {{10, 0.000001}, {100, 0.000013}, {1000, 0.001178}, {10000, 0.109915}, {100000, 10.190043}};  (* точки для первого графика *)
points2 = {{10, 0.000002}, {100, 0.000037}, {1000, 0.004226}, {10000, 0.376206}, {100000, 33.480685}};  (* точки для второго графика *)

ListPlot[{points1, points2}, Joined -> True, PlotStyle -> {Blue, Red},
    PlotMarkers -> Automatic, Frame -> True, FrameLabel -> {"X", "Y"},
    PlotLegends -> {"Array", "List"}]