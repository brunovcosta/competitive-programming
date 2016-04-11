function love.update()
	if love.keyboard.isDown("q") then
		love.event.quit()
	end
end
red={255,0,0}
green={0,255,0}
blue={0,0,255}
yellow={255,255,0}
white={255,255,255}
origin = {x=320,y=240}
holes={
	00, 20,
	40, 60,
	100, 120,
	140, 160
}
points={
	80, 20,
	100, 100,
	120, 140,
}
function bsearch(point,heights,min,max)
	i=math.floor((min+max)/2)
	deltaPoint={
		x=origin.x+point.x-love.mouse.getX(),
		y=origin.y+point.y-love.mouse.getY()
	}
	deltaHeight={
		x=origin.x-love.mouse.getX(),
		y=heights[i]-love.mouse.getY()
	}
	deltaHeightMax={
		x=origin.x-love.mouse.getX(),
		y=heights[max]-love.mouse.getY()
	}
	divPoint=deltaPoint.y/deltaPoint.x
	divHeight=deltaHeight.y/deltaHeight.x
	divHeightMax=deltaHeightMax.y/deltaHeightMax.x
	if(min==i) then
		if divPoint<divHeight then
			return 0;
		end
		if divPoint>divHeightMax then
			return max;
		end
		return i
	else

		if(divPoint>divHeight) then
			return bsearch(point,heights,i,max)
		end
		if(divPoint<divHeight) then
			return bsearch(point,heights,min,i)
		end
		if(divPoint==divHeight) then
			return i%2==0 and i-1 or i+1
		end
	end
end
function safe(point,heights)
	retVal =bsearch(point,heights,1,table.getn(heights)) 
	love.graphics.setColor(blue)
	love.graphics.print(retVal,origin.x+point.x,origin.y+point.y)
	return retVal%2==1
end
function love.draw()
	if love.keyboard.isDown('a') then
		table.insert(points,(love.mouse.getX()-300))
		table.insert(points,(love.mouse.getY()-300))
	end
	farDistance=640
	heights={}
	delta={}
	--loop lines
	for i=1,table.getn(holes),1 do
		heights[i] = origin.y+holes[i]
		delta[i]={
			x=origin.x-love.mouse.getX(),
			y=heights[i]-love.mouse.getY()
		}
		ray = {
			love.mouse.getX(),love.mouse.getY(),
			origin.x,heights[i]
		}
		prolongedRay = {
			love.mouse.getX(),love.mouse.getY(),
			origin.x+farDistance,heights[i]+farDistance*(delta[i].y/delta[i].x)
		}

		if i%2==0 then
			love.graphics.setColor(yellow)
			wall = {origin.x,heights[i],origin.x,heights[i-1]}
			love.graphics.line(wall)
		end
		--draw lines
		love.graphics.setColor(green)
		love.graphics.line(prolongedRay)
		love.graphics.setColor(red)
		love.graphics.line(ray)
	end

	--loop points
	for i=1,table.getn(points),2 do
		point = {x=points[i],y=points[i+1]}

		--draw points
		love.graphics.setColor(safe(point,heights) and white or red)
		love.graphics.setPointSize(4)
		love.graphics.points(point.x+origin.x,origin.y+point.y)
	end

	--draw mouse
	love.graphics.print(love.mouse.getX()-origin.x,love.mouse.getX()-50,love.mouse.getY());
	love.graphics.print(love.mouse.getY()-origin.y,love.mouse.getX()-50,love.mouse.getY()+10);
end
