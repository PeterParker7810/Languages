import pygame
pygame.init()

# Setting the Screen
screen_width = 800 # in pixels
screen_height = 600 # in pixels
screen = pygame.display.set_mode((screen_width, screen_height))
pygame.display.set_caption("Runner")
clock = pygame.time.Clock() # To set the FPS

# Setting a Surface
surface_width = 80 # in pixels
surface_height = 60 # in pixels
surface = pygame.Surface((surface_width, surface_height))
surface.fill((0, 0, 255)) # Blue

while True:
    for event in pygame.event.get(): # Get all the events that have happened
        if event.type == pygame.QUIT:
            pygame.quit()  
            quit()
    
    screen.blit(surface, (0,0)) # Blit the surface to the screen
    pygame.display.update()
    clock.tick(60) # 60 Frames Per Second