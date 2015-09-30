After applying movement, check for and resolve collisions.
Determine the tiles the player overlaps based on the player's bounding box.
Iterate through all of those tiles doing the following: (it's usually not very many unless your player is huge compared to your world tiles)
                                                         If the tile being checked isn't passable:
                                                         Determine how far on the X and Y axes the player is overlapping the non-passable tile
                                                         Resolve collision by moving the player out of that tile only on the shallow axis (whichever axis is least penetrated)
                                                         For example, if Y is the shallow axis and the collision is below, shift the player up to no longer overlap that tile.
                                                         Something like this: if(abs(overlap.y) < abs(overlap.x)) { position.y += overlap.y; } else { position.x += overlap.x; }
                                                         Update the bounding box's position based on the player's new position
                                                         Move on to the next tile...
                                                         If the tile being checked is passable, do nothing
                                                         If it's possible that resolving a collision could move the player into another collision, you may want to run through the above algorithm a second time. Or redesign your level.
                                                         
                                                         So I implemented this algorithm, and it works perfectly fine!
                                                         
                                                         
                                                         
                                                         I should look something like this:
                                                         
                                                         public void handleCollisions(GameObject player){
                                                                 
                                                                 for(int i = 0; i < levelObjects.size(); i++){
                                                                         GameObject tile = levelObjects.get(i);
                                                                         
                                                                         if(tile.collidesWith(player)){
                                                                                 float overX = ((player.width+tile.width)/2.0)-Math.abs(player.x-tile.position.x);
                                                                                 float overY = ((player.height+tile.height)/2.0)-Math.abs(player.y-tile.position.y);
                                                                                 
                                                                                 if(overY > overX){
                                                                                         if(player.x > tile.position.x)
                                                                                                 player.move(overX,0);
                                                                                         else
                                                                                                 player.move(-overX,0);
                                                                                 }else{
                                                                                         if(player.velocity.y > 0.0)
                                                                                                 player.move(0,-overY);
                                                                                         else
                                                                                                 player.move(0,overY);
                                                                                 }
                                                                         }
                                                                 }
                                                                 
                                                                 You should run this after the player position was updated.