blue={0,0,255}
red={255,0,0}
origin={x=200,y=200}
function readVars()
	s=io.read()
	k=io.read()
	w=io.read()
	kids={}
	walls={}
	for i=1,k do
		kid = {
			x=io.read(),
			y=io.read()
		}
		table.insert(kids,kid)
	end
	for i=1,w do
		wall = {
			p1={
				x=io.read(),
				y=io.read()
			},
			p2={
				x=io.read(),
				y=io.read()
			}
		}
		table.insert(walls,wall)
	end
end
readVars()
function love.draw()
	love.graphics.setPointSize(4)
	love.graphics.setColor(blue)
	for i=1,table.getn(kids) do
		love.graphics.points(kids[i].x+origin.x,kids[i].y+origin.y)
		love.graphics.print(kids[i].x,kids[i].x+origin.x,kids[i].y+origin.y)
		love.graphics.print(kids[i].y,kids[i].x+origin.x,kids[i].y+origin.y)
	end
	love.graphics.setColor(red)
	for i=1,table.getn(walls) do
		love.graphics.line(
			walls[i].p1.x+origin.x,
			walls[i].p1.y+origin.y,
			walls[i].p2.x+origin.x,
			walls[i].p2.y+origin.y
		)
	end
end
