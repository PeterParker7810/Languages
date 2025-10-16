import pygame
import time
import random
pygame.init()

class Game_Main:
    game_mode = 0
    width, height = 1050, 700
    Home_Music = True
    score = 0

    def __init__(self):
        self.screen = pygame.display.set_mode((self.width, self.height))
        pygame.display.set_caption("Among Us Endless Runner")
        self.clock = pygame.time.Clock()

    def HomeScreen_Game_Loop(self):
        # Background Music
        pygame.mixer.music.load(r"C:\Users\3QIN\OneDrive\Desktop\Languages\Python\Projects\Pygame\Among-Us_Endless Runner\AUER_Audios\Bg_Music.mp3")
        pygame.mixer.music.play(-1)  # Loop the background music

        # Background Image and Surface
        text = pygame.font.Font(None, 150)
        BG = pygame.image.load(r"C:\Users\3QIN\OneDrive\Desktop\Languages\Python\Projects\Pygame\Among-Us_Endless Runner\AUER_Images\HomeScreen\Sky_BG.jpg")
        Surface = pygame.image.load(r"C:\Users\3QIN\OneDrive\Desktop\Languages\Python\Projects\Pygame\Among-Us_Endless Runner\AUER_Images\HomeScreen\surface.png")
        text_surface = text.render("Can you Survive?", True, (255, 255, 255)) # Font Surface

        # Start Icon
        start_text = pygame.font.Font(None, 50)
        start_surface = start_text.render("Click to Begin!", True, (255,255,255), (0,0,155))
        start_rect = start_surface.get_rect(center=(self.width/2, 200))  # Center the start button

        # Character Animation
        frame1 = pygame.image.load(r"C:\Users\3QIN\OneDrive\Desktop\Languages\Python\Projects\Pygame\Among-Us_Endless Runner\AUER_Images\Characters\Walking_Frame-1.png")
        frame2 = pygame.image.load(r"C:\Users\3QIN\OneDrive\Desktop\Languages\Python\Projects\Pygame\Among-Us_Endless Runner\AUER_Images\Characters\Walking_Frame-2.png")
        frame3 = pygame.image.load(r"C:\Users\3QIN\OneDrive\Desktop\Languages\Python\Projects\Pygame\Among-Us_Endless Runner\AUER_Images\Characters\Walking_Frame-3.png")
        frame4 = pygame.image.load(r"C:\Users\3QIN\OneDrive\Desktop\Languages\Python\Projects\Pygame\Among-Us_Endless Runner\AUER_Images\Characters\Walking_Frame-4.png")
        char = [frame1, frame2, frame3, frame4] # List of character frames
        curr_frame = 0  # Current frame index
        frame_delay = 200
        last_update = pygame.time.get_ticks() 
        char_x, char_y = 0, 340  # Character position
        
        while True:
            for event in pygame.event.get():
                if event.type == pygame.QUIT:
                    pygame.quit()
                    return
                
                if event.type == pygame.MOUSEBUTTONDOWN:
                    click_sound = pygame.mixer.Sound(r"C:\Users\3QIN\OneDrive\Desktop\Languages\Python\Projects\Pygame\Among-Us_Endless Runner\AUER_Audios\Click_SE.mp3")
                    click_sound.play()  # Play click sound on mouse button down
                
            # Fill the screen with the background image
            self.screen.blit(BG, (0, 0))
            self.screen.blit(Surface, (0, 120))
            self.screen.blit(text_surface, (self.width // 2 - text_surface.get_width() // 2, 50))
            self.screen.blit(start_surface, ((self.width/2)-170, 180))
            self.screen.blit(char[curr_frame%len(char)], (char_x, char_y))

            # Update character animation
            curr_time = pygame.time.get_ticks()
            if curr_time - last_update > frame_delay:
                curr_frame += 1
                last_update = curr_time

            char_x += 5 # Move character to the right
            if char_x > self.width:
                char_x = -char[0].get_width() # Reset character position

            # Checking for mouse click to start the game
            mouse_pos = pygame.mouse.get_pos()
            if event.type == pygame.MOUSEBUTTONDOWN and start_rect.collidepoint(mouse_pos):
                time.sleep(0.5)
                self.game_mode = 1
                return
                
            pygame.display.update()
            self.clock.tick(60)

    def Loading_Screen_Game_Loop(self):
        # Setup Loading Screen
        screen = pygame.display.set_mode((self.width, self.height))
        pygame.display.set_caption("Among Us Endless Runner")
        clock = pygame.time.Clock()

        # Loading Delay
        loading_duration = 15000  # 3 seconds in milliseconds
        start_time = pygame.time.get_ticks()

        # Loading Text
        loading_text = pygame.font.Font(None, 100)
        loading_surface1 = loading_text.render("Loading", True, (255, 255, 255))
        loading_surface2 = loading_text.render("Loading.", True, (255, 255, 255))
        loading_surface3 = loading_text.render("Loading..", True, (255, 255, 255))
        loading_surface4 = loading_text.render("Loading...", True, (255, 255, 255))
        loading_surfaces = [loading_surface1, loading_surface2, loading_surface3, loading_surface4]
        loading_index = 0  # Index for loading text animation
        delay = 300
        last_update_text = pygame.time.get_ticks()  # Last update time for loading text animation

        # Character Animation
        frame1 = pygame.image.load(r"C:\Users\3QIN\OneDrive\Desktop\Languages\Python\Projects\Pygame\Among-Us_Endless Runner\AUER_Images\Characters\Loading_Frame-1.png")
        frame2 = pygame.image.load(r"C:\Users\3QIN\OneDrive\Desktop\Languages\Python\Projects\Pygame\Among-Us_Endless Runner\AUER_Images\Characters\Loading_Frame-2.png")
        frame3 = pygame.image.load(r"C:\Users\3QIN\OneDrive\Desktop\Languages\Python\Projects\Pygame\Among-Us_Endless Runner\AUER_Images\Characters\Loading_Frame-3.png")
        frame4 = pygame.image.load(r"C:\Users\3QIN\OneDrive\Desktop\Languages\Python\Projects\Pygame\Among-Us_Endless Runner\AUER_Images\Characters\Loading_Frame-4.png")
        char = [frame1, frame2, frame3, frame4]  # List of character frames
        curr_frame = 0  # Current frame index
        frame_delay = 150
        last_update = pygame.time.get_ticks() 
        char_x, char_y = 0, 300  # Character position

        # Game Loop
        while True:
            screen.fill((0, 0, 0))  # Clear the screen with black
            for event in pygame.event.get():
                if event.type == pygame.QUIT:
                    pygame.quit()
                    return
                
                if event.type == pygame.MOUSEBUTTONDOWN:
                        click_sound = pygame.mixer.Sound(r"C:\Users\3QIN\OneDrive\Desktop\Languages\Python\Projects\Pygame\Among-Us_Endless Runner\AUER_Audios\Click_SE.mp3")
                        click_sound.play()  # Play click sound on mouse button down

            # Blitting Objects
            screen.blit(char[curr_frame % len(char)], (char_x, char_y))
            screen.blit(loading_surfaces[loading_index%len(loading_surfaces)], (self.width//2 - loading_surfaces[loading_index%len(loading_surfaces)].get_width()//2, self.height//2 - (loading_surfaces[loading_index%len(loading_surfaces)].get_height()//2 + 100)))

            # Update character animation
            curr_time = pygame.time.get_ticks()
            if curr_time - last_update > frame_delay:
                curr_frame += 1
                last_update = curr_time

            # Update loading text animation
            curr_time1 = pygame.time.get_ticks()
            if curr_time1 - last_update_text > delay:
                loading_index += 1
                last_update_text = curr_time

            char_x += 5 # Move character to the right
            if char_x > self.width:
                char_x = -char[0].get_width() # Reset character position

            # Check if loading duration has passed
            if pygame.time.get_ticks() - start_time >= loading_duration:
                self.game_mode = 2
                pygame.mixer.music.stop()  # Stop any music playing
                return
            
            loading_duration -= clock.get_time()  # Decrease loading delay by the time passed since last frame

            pygame.display.update()
            clock.tick(60)

    def Game_main_Loop(self):
        # Setup display
        screen = pygame.display.set_mode((self.width, self.height))
        pygame.display.set_caption("Among Us Endless Runner")
        clock = pygame.time.Clock()

        # Load Background Images
        BG = pygame.image.load(r"C:\Users\3QIN\OneDrive\Desktop\Languages\Python\Projects\Pygame\Among-Us_Endless Runner\AUER_Images\Game_Main\Space.jpg")
        surface = pygame.image.load(r"C:\Users\3QIN\OneDrive\Desktop\Languages\Python\Projects\Pygame\Among-Us_Endless Runner\AUER_Images\Game_Main\Surface.png")

        # Countdown Setup
        countdown_sound = pygame.mixer.Sound(r"C:\Users\3QIN\OneDrive\Desktop\Languages\Python\Projects\Pygame\Among-Us_Endless Runner\AUER_Audios\countdown.mp3")
        countdown_font = pygame.font.Font(None, 100)
        countdown_time = 5
        countdown_delay = 1000
        countdown_start = pygame.time.get_ticks()
        last_count_value = countdown_time

        # Display High Score
        high_score_font = pygame.font.Font(None, 50)
        high_score = open(r"C:\Users\3QIN\OneDrive\Desktop\Languages\Python\Projects\Pygame\Among-Us_Endless Runner\Game_Data.txt", "r+")
        high_score_value = int(high_score.read().strip())

        # Main Character Animation
        frame1 = pygame.image.load(r"C:\Users\3QIN\OneDrive\Desktop\Languages\Python\Projects\Pygame\Among-Us_Endless Runner\AUER_Images\Characters\Walking_Frame-1.png")
        frame2 = pygame.image.load(r"C:\Users\3QIN\OneDrive\Desktop\Languages\Python\Projects\Pygame\Among-Us_Endless Runner\AUER_Images\Characters\Walking_Frame-2.png")
        frame3 = pygame.image.load(r"C:\Users\3QIN\OneDrive\Desktop\Languages\Python\Projects\Pygame\Among-Us_Endless Runner\AUER_Images\Characters\Walking_Frame-3.png")
        frame4 = pygame.image.load(r"C:\Users\3QIN\OneDrive\Desktop\Languages\Python\Projects\Pygame\Among-Us_Endless Runner\AUER_Images\Characters\Walking_Frame-4.png")
        char = [frame1, frame2, frame3, frame4]
        curr_frame = 0
        frame_delay = 200
        last_update = pygame.time.get_ticks()
        char_x, char_y = -500, 370

        # Jumping Logic
        is_jumping = False
        jump_velocity = -27
        gravity = 1
        ground_y = char_y

        # Music Playlist
        music_list = [
            r"C:\Users\3QIN\OneDrive\Desktop\Languages\Python\Projects\Pygame\Among-Us_Endless Runner\AUER_Audios\Game Music\Song-1.mp3",
            r"C:\Users\3QIN\OneDrive\Desktop\Languages\Python\Projects\Pygame\Among-Us_Endless Runner\AUER_Audios\Game Music\Song-2.mp3",
            r"C:\Users\3QIN\OneDrive\Desktop\Languages\Python\Projects\Pygame\Among-Us_Endless Runner\AUER_Audios\Game Music\Song-3.mp3",
            r"C:\Users\3QIN\OneDrive\Desktop\Languages\Python\Projects\Pygame\Among-Us_Endless Runner\AUER_Audios\Game Music\Song-4.mp3",
            r"C:\Users\3QIN\OneDrive\Desktop\Languages\Python\Projects\Pygame\Among-Us_Endless Runner\AUER_Audios\Game Music\Song-5.mp3",
            r"C:\Users\3QIN\OneDrive\Desktop\Languages\Python\Projects\Pygame\Among-Us_Endless Runner\AUER_Audios\Game Music\Song-6.mp3",
            r"C:\Users\3QIN\OneDrive\Desktop\Languages\Python\Projects\Pygame\Among-Us_Endless Runner\AUER_Audios\Game Music\Song-7.mp3",
        ]
        current_music = None
        music_started = False

        # Scrolling variables
        bg_x = 0
        surface_x = 0
        scroll_speed = 2
        max_scroll_speed = 40
        max_enemy_speed = 80
        speed_increment = 0.5
        speed_update_interval = 5000  # every 5 seconds
        last_speed_update = pygame.time.get_ticks()
        scrolling_enabled = False

        # Score
        score = 0
        score_font = pygame.font.Font(None, 50)
        score_delay = 1000
        score_bonus = 0
        last_score_update = pygame.time.get_ticks()

        # Auto walk-in
        auto_move_done = False

        # Enemies
        enemies = [
            pygame.image.load(r"C:\Users\3QIN\OneDrive\Desktop\Languages\Python\Projects\Pygame\Among-Us_Endless Runner\AUER_Images\Enemies\Enemy-1.png"),
            pygame.image.load(r"C:\Users\3QIN\OneDrive\Desktop\Languages\Python\Projects\Pygame\Among-Us_Endless Runner\AUER_Images\Enemies\Enemy-2.png"),
            pygame.image.load(r"C:\Users\3QIN\OneDrive\Desktop\Languages\Python\Projects\Pygame\Among-Us_Endless Runner\AUER_Images\Enemies\Enemy-3.png"),
            pygame.image.load(r"C:\Users\3QIN\OneDrive\Desktop\Languages\Python\Projects\Pygame\Among-Us_Endless Runner\AUER_Images\Enemies\Enemy-4.png"),
        ]
        enemy_list = []
        enemy_spawn_delay = random.randint(1500, 3000)
        last_enemy_spawn_time = pygame.time.get_ticks()
        enemy_speed = 5
        enemy_spawn = False

        while True:
            for event in pygame.event.get():
                if event.type == pygame.QUIT:
                    pygame.mixer.music.stop()
                    pygame.quit()
                    return
                if event.type == pygame.MOUSEBUTTONDOWN:
                    click = pygame.mixer.Sound(r"C:\Users\3QIN\OneDrive\Desktop\Languages\Python\Projects\Pygame\Among-Us_Endless Runner\AUER_Audios\Click_SE.mp3")
                    click.play()
                if event.type == pygame.KEYDOWN:
                    if event.key == pygame.K_SPACE and not is_jumping:
                        jump_sound = pygame.mixer.Sound(r"C:\Users\3QIN\OneDrive\Desktop\Languages\Python\Projects\Pygame\Among-Us_Endless Runner\AUER_Audios\Jump_SE.mp3")
                        jump_sound.play()
                        is_jumping = True
                        velocity_y = jump_velocity

            current_time = pygame.time.get_ticks()

            if current_time - last_enemy_spawn_time > enemy_spawn_delay and scrolling_enabled:
                enemy_img = random.choice(enemies)
                enemy_x = self.width
                enemy_y = 400
                enemy_list.append({'x': enemy_x, 'y': enemy_y, 'img': enemy_img})
                last_enemy_spawn_time = current_time
                enemy_spawn_delay = random.randint(1500-score_bonus, 3000-score_bonus)

            for enemy in enemy_list[:]:
                enemy['x'] -= enemy_speed
                if enemy['x'] < -enemy['img'].get_width():
                    enemy_list.remove(enemy)

            # Collision check
            char_rect = pygame.Rect(char_x, char_y, char[0].get_width(), char[0].get_height())
            for enemy in enemy_list:
                enemy_rect = pygame.Rect(enemy['x'], enemy['y'], enemy['img'].get_width(), enemy['img'].get_height())
                if char_rect.colliderect(enemy_rect):
                    print("Collision! Game Over.")
                    game_over_sound = pygame.mixer.Sound(r"C:\Users\3QIN\OneDrive\Desktop\Languages\Python\Projects\Pygame\Among-Us_Endless Runner\AUER_Audios\Kill_SE.mp3")
                    game_over_sound.play()
                    self.score = score
                    self.game_mode = 3
                    return

            if scrolling_enabled:
                enemy_spawn = True
                bg_x -= scroll_speed
                surface_x -= scroll_speed
                if bg_x <= -self.width:
                    bg_x = 0
                if surface_x <= -self.width:
                    surface_x = 0

                current_score_time = pygame.time.get_ticks()
                if current_score_time - last_score_update >= score_delay:
                    score += 100 + score_bonus
                    last_score_update = current_score_time

            screen.blit(BG, (bg_x, 0))
            screen.blit(BG, (bg_x + self.width, 0))
            screen.blit(surface, (surface_x, 120))
            screen.blit(surface, (surface_x + self.width, 120))
            screen.blit(score_font.render(f"Score: {score}", True, (255, 255, 255)), (10, 50))
            screen.blit(high_score_font.render(f"High Score: {high_score_value}", True, (255, 255, 255)), (10, 10))

            if enemy_spawn:
                for enemy in enemy_list:
                    screen.blit(enemy['img'], (enemy['x'], enemy['y']))

            if score > high_score_value:
                high_score_value = score
                high_score.seek(0)
                high_score.write(str(high_score_value))

            if countdown_time > 0:
                screen.blit(countdown_font.render(str(countdown_time), True, (255, 255, 255)), (self.width // 2 - 50, 50))
                countdown_sound.play()

                if countdown_time != last_count_value:
                    last_count_value = countdown_time

            elif countdown_time == 0:
                screen.blit(countdown_font.render("Goo!!!", True, (255, 255, 255)), (self.width // 2 - 100, 50))

            else:
                scrolling_enabled = True
                if not auto_move_done:
                    if char_x < 50:
                        char_x += 5
                    else:
                        auto_move_done = True

                keys = pygame.key.get_pressed()
                if auto_move_done:
                    if keys[pygame.K_RIGHT] and char_x < self.width - 130:
                        char_x += 5
                    if keys[pygame.K_LEFT] and char_x > 0:
                        char_x -= 5

                if not pygame.mixer.music.get_busy():
                    next_track = random.choice([i for i in music_list if i != current_music])
                    pygame.mixer.music.load(next_track)
                    pygame.mixer.music.play()
                    current_music = next_track
                    music_started = True

                screen.blit(char[curr_frame % len(char)], (char_x, char_y))

            if current_time - countdown_start >= countdown_delay:
                countdown_time -= 1
                countdown_start = current_time

            curr_time = pygame.time.get_ticks()
            if curr_time - last_update > frame_delay:
                curr_frame += 1
                last_update = curr_time

            if is_jumping:
                char_y += velocity_y
                velocity_y += gravity
                if char_y >= ground_y:
                    char_y = ground_y
                    is_jumping = False
                    velocity_y = 0

            # Increase speed gradually with limit
            if current_time - last_speed_update >= speed_update_interval:
                if scroll_speed < max_scroll_speed:
                    scroll_speed += speed_increment
                if enemy_speed < max_enemy_speed:
                    enemy_speed += speed_increment
                    enemy_spawn_delay = random.randint(1500 - score_bonus, 3000- score_bonus)  # Adjust enemy spawn delay based on score bonus
                last_speed_update = current_time
                frame_delay = max(50, frame_delay - 5)  # Increase frame rate by decreasing delay
                score_bonus += 10  # Increase score bonus for faster gameplay

            pygame.display.update()
            clock.tick(60)


    def Game_Over_Loop(self):
        # Stop any music playing
        pygame.mixer.music.stop()
        
        # Setup Game Over Screen
        screen = pygame.display.set_mode((self.width, self.height))
        pygame.display.set_caption("Among Us Endless Runner")
        clock = pygame.time.Clock()

        # Game Over Text
        game_over_font = pygame.font.Font(None, 100)
        game_over_surface = game_over_font.render("Game Over", True, (255, 0, 0))

        # Restart Text
        restart_font = pygame.font.Font(None, 50)
        restart_surface = restart_font.render("Click to Exit", True, (255, 255, 255))

        # Score Display
        score_font = pygame.font.Font(None, 50)
        score_surface = score_font.render(f"Your Score: {self.score}", True, (255, 255, 255))
        high_score_font = pygame.font.Font(None, 50)
        high_score = open(r"C:\Users\3QIN\OneDrive\Desktop\Languages\Python\Projects\Pygame\Among-Us_Endless Runner\Game_Data.txt", "r+")
        high_score_value = int(high_score.read().strip())

        while True:
            for event in pygame.event.get():
                if event.type == pygame.QUIT:
                    pygame.quit()
                    return
                if event.type == pygame.MOUSEBUTTONDOWN:
                    self.game_mode = 0
                    return

            screen.fill((0, 0, 0))
            screen.blit(game_over_surface, (self.width // 2 - game_over_surface.get_width() // 2, (self.height // 2 - game_over_surface.get_height() // 2)-50))
            screen.blit(restart_surface, (self.width // 2 - restart_surface.get_width() // 2, (self.height // 2 + game_over_surface.get_height())-50))
            screen.blit(score_surface, (self.width // 2 - score_surface.get_width() // 2, (self.height // 2 + game_over_surface.get_height() + 50)-50))
            screen.blit(high_score_font.render(f"High Score: {high_score_value}", True, (255, 255, 255)), (self.width // 2 - high_score_font.render(f"High Score: {high_score_value}", True, (255, 255, 255)).get_width() // 2, (self.height // 2 + game_over_surface.get_height() + 100)-50))

            pygame.display.update()
            clock.tick(60)

# Main Game Loop
Player1 = Game_Main()
if (Player1.game_mode == 0):
    Player1.HomeScreen_Game_Loop()

if (Player1.game_mode == 1):
    Player1.Loading_Screen_Game_Loop()

if (Player1.game_mode == 2):
    Player1.Game_main_Loop()

if (Player1.game_mode == 3):
    Player1.Game_Over_Loop()