points1 = {{10, 0.000002}, {100, 0.000008}, {1000, 0.000084}, {10000, 0.001116}, {100000, 0.012172}};  (* точки для первого графика *)
points2 = {{10, 0.000002}, {100, 0.000008}, {1000, 0.000139}, {10000, 0.001516}, {100000, 0.017832}};  (* точки для второго графика *)

ListPlot[{points1, points2}, Joined -> True, PlotStyle -> {Blue, Red},
    PlotMarkers -> Automatic, Frame -> True, FrameLabel -> {"X", "Y"},
    PlotLegends -> {"Array", "List"}]