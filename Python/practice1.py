import pygame
import time
pygame.init()

# Set up the Display
width, height = 1050, 700
pygame.display.set_caption("Pygame Window")
screen = pygame.display.set_mode((width, height))
clock = pygame.time.Clock() # To set the frame rate
text = pygame.font.Font(None, 150) # Font style and size

# Background and Surface
BG = pygame.image.load(r"C:\Users\3QIN\OneDrive\Desktop\Languages\Python\Projects\Pygame_Images\Sky_BG.jpg")
Surface = pygame.image.load(r"C:\Users\3QIN\OneDrive\Desktop\Languages\Python\Projects\Pygame_Images\surface.png")
text_surface = text.render("Let's Play!", True, (255, 255, 255)) # Font Surface

# Character Position
frame1 = pygame.image.load(r"C:\Users\3QIN\OneDrive\Desktop\Languages\Python\Projects\Pygame_Images\Among Us Frames\Walking_Frame-1.png")
frame2 = pygame.image.load(r"C:\Users\3QIN\OneDrive\Desktop\Languages\Python\Projects\Pygame_Images\Among Us Frames\Walking_Frame-2.png")
frame3 = pygame.image.load(r"C:\Users\3QIN\OneDrive\Desktop\Languages\Python\Projects\Pygame_Images\Among Us Frames\Walking_Frame-3.png")
frame4 = pygame.image.load(r"C:\Users\3QIN\OneDrive\Desktop\Languages\Python\Projects\Pygame_Images\Among Us Frames\Walking_Frame-4.png")
char = [frame1, frame2, frame3, frame4]  # List of character frames for animation
curr_frame = 0
frame_delay = 200 # Delay in milliseconds for frame change
update_interval = pygame.time.get_ticks() # Update every second
char_x, char_y = 0, 280

# Music

while True:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            pygame.quit()
            exit()

    screen.blit(BG, (0,0)) # Background Image
    screen.blit(Surface, (0,120)) # Surface Image
    screen.blit(text_surface, (250, 50)) # Text 
    screen.blit(char[curr_frame%len(char)], (char_x, char_y)) # Character Image
    pygame.display.update()

    curr_time = pygame.time.get_ticks()  # Get the current time in milliseconds
    if (curr_time - update_interval) > frame_delay:
        curr_frame += 1  # Update the frame for animation
        update_interval = curr_time

    clock.tick(60)  # Limit the frame rate to 60 FPS

    char_x += 5  # Move character to the right
    if char_x > width:  # Reset character position if it goes off screen
        char_x = -frame1.get_width()