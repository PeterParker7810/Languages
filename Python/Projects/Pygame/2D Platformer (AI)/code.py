import pygame
import sys

# Initialize Pygame
pygame.init()

# Screen settings
SCREEN_WIDTH, SCREEN_HEIGHT = 800, 600
screen = pygame.display.set_mode((SCREEN_WIDTH, SCREEN_HEIGHT))
pygame.display.set_caption("2D Platformer")

# Colors
WHITE = (255, 255, 255)
BLACK = (0, 0, 0)
BLUE = (0, 0, 255)
GREEN = (0, 255, 0)
RED = (255, 0, 0)

# Clock for managing frame rate
clock = pygame.time.Clock()
FPS = 60
# Player settings
player_width, player_height = 130, 100
player_x, player_y = 100, 500
player_speed = 5
player_jump_power = 15
player_velocity_y = 0
is_jumping = False

gravity = 0.8

# Platform settings (using image)
platform_image = pygame.image.load("platform.png")  # Replace with your platform image path
platform_image = pygame.transform.scale(platform_image, (200, 20))  # Adjust the size as needed
platforms = [
    pygame.Rect(100, 500, 200, 20),
    pygame.Rect(400, 400, 200, 20),
    pygame.Rect(650, 300, 100, 20),
    pygame.Rect(200, 200, 150, 20),
    pygame.Rect(500, 150, 200, 20),
]

# Goal settings
goal = pygame.Rect(750, 100, 40, 40)

# Load background image
background_image = pygame.image.load("PzhsEkqf6t28TJ15JNrj1zGk3cZW91erTYfSgpdD.png")
background_image = pygame.transform.scale(background_image, (SCREEN_WIDTH, SCREEN_HEIGHT))


# Player settings (using image)
player_image = pygame.image.load("Screenshot__17_-removebg-preview.png")  # Replace with your player image path
player_image = pygame.transform.scale(player_image, (player_width, player_height))  # Adjust the size as needed

# Function to draw the player using the image
def draw_player(x, y): 
    # Draw player image
    screen.blit(player_image, (x, y))


def draw_platforms():
    for platform in platforms:
        # Draw platform image
        screen.blit(platform_image, (platform.x, platform.y))

def draw_goal():
    pygame.draw.rect(screen, RED, goal)

# Game loop
running = True
while running:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False

    # Handle input
    keys = pygame.key.get_pressed()
    if keys[pygame.K_LEFT] and player_x > 0:
        player_x -= player_speed
    if keys[pygame.K_RIGHT] and player_x + player_width < SCREEN_WIDTH:
        player_x += player_speed
    if keys[pygame.K_SPACE] and not is_jumping:
        is_jumping = True
        player_velocity_y = -player_jump_power

    # Apply gravity
    player_velocity_y += gravity
    player_y += player_velocity_y

    # Check collision with platforms
    for platform in platforms:
        if player_y + player_height > platform.top and player_y + player_height - player_velocity_y <= platform.top and player_x + player_width > platform.left and player_x < platform.right:
            # Prevent jumping through platforms
            if player_velocity_y > 0:
                player_y = platform.top - player_height
                player_velocity_y = 0
                is_jumping = False

    # Prevent falling below the screen
    if player_y + player_height > SCREEN_HEIGHT:
        player_y = SCREEN_HEIGHT - player_height
        player_velocity_y = 0
        is_jumping = False

    # Prevent moving out of the screen vertically
    if player_y < 0:
        player_y = 0

    # Check if the player reaches the goal
    if player_x + player_width > goal.left and player_x < goal.right and player_y + player_height > goal.top and player_y < goal.bottom:
        print("You reached the goal! Congratulations!")
        running = False

    # Draw background
    screen.blit(background_image, (0, 0))

    # Draw everything
    draw_player(player_x, player_y)
    draw_platforms()
    draw_goal()

    # Update display
    pygame.display.flip()

    # Cap the frame rate
    clock.tick(FPS)

# Quit Pygame
pygame.quit()
sys.exit() # type: ignore