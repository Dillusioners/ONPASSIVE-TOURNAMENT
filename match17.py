import pygame
import random

# Game settings
WIDTH = 800
HEIGHT = 600
FPS = 10
GRID_SIZE = 20

# Colors
BLACK = (0, 0, 0)
GREEN = (0, 255, 0)
RED = (255, 0, 0)

# Initialize Pygame
pygame.init()
screen = pygame.display.set_mode((WIDTH, HEIGHT))
pygame.display.set_caption("Snake Game")
clock = pygame.time.Clock()

# Snake class


class Snake:
    def __init__(self):
        self.body = [(WIDTH / 2, HEIGHT / 2)]
        self.direction = "right"

    def move(self):
        head = self.body[0]
        x, y = head

        if self.direction == "up":
            y -= GRID_SIZE
        elif self.direction == "down":
            y += GRID_SIZE
        elif self.direction == "left":
            x -= GRID_SIZE
        elif self.direction == "right":
            x += GRID_SIZE

        self.body.insert(0, (x, y))
        self.body.pop()

    def change_direction(self, direction):
        if direction == "up" and self.direction != "down":
            self.direction = "up"
        elif direction == "down" and self.direction != "up":
            self.direction = "down"
        elif direction == "left" and self.direction != "right":
            self.direction = "left"
        elif direction == "right" and self.direction != "left":
            self.direction = "right"

    def grow(self):
        tail = self.body[-1]
        x, y = tail

        if self.direction == "up":
            y += GRID_SIZE
        elif self.direction == "down":
            y -= GRID_SIZE
        elif self.direction == "left":
            x += GRID_SIZE
        elif self.direction == "right":
            x -= GRID_SIZE

        self.body.append((x, y))

    def draw(self):
        for segment in self.body:
            pygame.draw.rect(
                screen, GREEN, (segment[0], segment[1], GRID_SIZE, GRID_SIZE))


# Food class
class Food:
    def __init__(self):
        self.position = self.random_position()

    def random_position(self):
        x = random.randint(0, (WIDTH - GRID_SIZE) // GRID_SIZE) * GRID_SIZE
        y = random.randint(0, (HEIGHT - GRID_SIZE) // GRID_SIZE) * GRID_SIZE
        return x, y

    def draw(self):
        pygame.draw.rect(
            screen, RED, (self.position[0], self.position[1], GRID_SIZE, GRID_SIZE))


# Game loop
def game_loop():
    running = True

    snake = Snake()
    food = Food()

    while running:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                running = False
            elif event.type == pygame.KEYDOWN:
                if event.key == pygame.K_UP:
                    snake.change_direction("up")
                elif event.key == pygame.K_DOWN:
                    snake.change_direction("down")
                elif event.key == pygame.K_LEFT:
                    snake.change_direction("left")
                elif event.key == pygame.K_RIGHT:
                    snake.change_direction("right")

        snake.move()

        if snake.body[0] == food.position:
            snake.grow()
            food.position = food.random_position()

        if snake.body[0][0] < 0 or snake.body[0][0] >= WIDTH or snake.body[0][1] < 0 or snake.body[0][1] >= HEIGHT:
            running = False

        if len(snake.body) > 1 and snake.body[0] in snake.body[1:]:
            running = False

        screen.fill(BLACK)
        snake.draw()
        food.draw()
        pygame.display.flip()
        clock.tick(FPS)

    pygame.quit()


# Start the game
game_loop()
