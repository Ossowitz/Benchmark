points1 = {{10, 0.000001}, {100, 0.000014}, {1000, 0.001042}, {10000, 0.158444}, {100000, 9.735776}};  (* точки для первого графика *)
points2 = {{10, 0.000002}, {100, 0.000010}, {1000, 0.000126}, {10000, 0.001695}, {100000, 0.017286}};  (* точки для второго графика *)

ListPlot[{points1, points2}, Joined -> True, PlotStyle -> {Blue, Red},
    PlotMarkers -> Automatic, Frame -> True, FrameLabel -> {"X", "Y"},
    PlotLegends -> {"Array", "List"}]