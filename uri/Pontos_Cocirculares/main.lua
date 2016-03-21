function incenter(p1,p2,p3)
	dax = p2.x-p3.x
	day = p2.y-p3.y
	dbx = p1.x-p3.x
	dby = p1.y-p3.y
	dcx = p2.x-p1.x
	dcy = p2.y-p1.y
	a = math.sqrt(dax*dax+day*day)
	b = math.sqrt(dbx*dbx+dby*dby)
	c = math.sqrt(dcx*dcx+dcy*dcy)
	return {
		x=(a*x1+b*x2+c*x3)/(a+b+c),
		y=(a*y1+b*y2+c*y3)/(a+b+c)
	}
end
function circle(points)
	incenters={}
	for i=0,getn(points),2 do
		for j=0,getn(points),2 do
			if i==j then break end
			for k=0,getn(points),2 do
				if i==k or j==k then break end
				p1={x=points[i],y=points[i+1]}
				p2={x=points[j],y=points[k+1]}
				p3={x=points[k],y=points[k+1]}
				table.insert(incenters,incenter(p1,p2,p3))
			end
		end
	end
end
red={255,0,0}
blue={0,255,0}
green={0,0,255}
origin={x=320,y=240}
points={
	-10, 0,
	0, -10,
	10, 0,
	0, 10,
	-20, 10,
	-10, 20,
	-2, 4
}

function love.draw()
	love.graphics.setColor(red)
	love.graphics.setPointSize(3)
	for i=1,#(points),2 do
		love.graphics.points(origin.x+points[i],origin.y+points[i+1]);
	end
end
