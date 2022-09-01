#include "../headers/window.h"
#include "../headers/game.h"

SDL_Window* m_window; 
SDL_GLContext m_gl_context;
SDL_Renderer* m_renderer;
	
GLuint TextureID[2];

ImGuiIO io;

bool isRunning = true,
     show_demo_window = true,
     show_another_window = false;

static const int SCREEN_WIDTH = 640;
static const int SCREEN_HEIGHT = 480; 



//-------------------------------------


void LaunchGui(const char* glsl_version, Inputs* inputs, SDL_Event event)
{
    IMGUI_CHECKVERSION(); 
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls

//Setup Dear ImGui style

    ImGui::StyleColorsDark();
    ImGui::StyleColorsClassic();

// Setup Platform/Renderer backends

    ImGui_ImplSDL2_InitForOpenGL(m_window, m_gl_context);
    ImGui_ImplOpenGL3_Init(glsl_version);

    //ImVec4 clear_color = ImVec4(0.55f, 0.25f, 0.60f, 1.00f);

   
};


//------------------------------------

void GuiPreUpdate(SDL_Event event)
{
    ImGui_ImplSDL2_ProcessEvent(&event);
    glClear(GL_COLOR_BUFFER_BIT);

    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplSDL2_NewFrame();
    ImGui::NewFrame();      

 // 1. Show the big demo window (Most of the sample code is in ImGui::ShowDemoWindow()! You can browse its code to learn more about Dear ImGui!).

    if (show_demo_window)
        ImGui::ShowDemoWindow(&show_demo_window);

    // // 2. Show a simple window that we create ourselves. We use a Begin/End pair to created a named window.
    // {
    //     static float f = 0.0f;
    //     static int counter = 0;

    //     ImGui::Begin("Hello, world!");                          // Create a window called "Hello, world!" and append into it.

    //     ImGui::Text("This is some useful text.");               // Display some text (you can use a format strings too)
    //     ImGui::Checkbox("Demo Window", &show_demo_window);      // Edit bools storing our window open/close state
    //     ImGui::Checkbox("Another Window", &show_another_window);

    //     ImGui::SliderFloat("float", &f, 0.0f, 1.0f);            // Edit 1 float using a slider from 0.0f to 1.0f
    //     //ImGui::ColorEdit3("clear color", (float*)&clear_color); // Edit 3 floats representing a color

    //     if (ImGui::Button("Button"))                            // Buttons return true when clicked (most widgets return true when edited/activated)
    //         counter++;
    //     ImGui::SameLine();
    //     ImGui::Text("counter = %d", counter);

    //     ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);

    //     ImGui::End();
    // }

    // // 3. Show another simple window.
    // if (show_another_window)
    // {
    //     ImGui::Begin("Another Window", &show_another_window);   // Pass a pointer to our bool variable (the window will have a closing button that will clear the bool when clicked)
    //     ImGui::Text("Hello from another window!");
    //     if (ImGui::Button("Close Me"))
    //         show_another_window = false;
    //     ImGui::End();
    // }
};

//----------------------------------


void RenderGui()
{
    ImGui::Render();
    glViewport(0, 0, (int)io.DisplaySize.x, (int)io.DisplaySize.y);
    //glClearColor(clear_color.x * clear_color.w, clear_color.y * clear_color.w, clear_color.z * clear_color.w, clear_color.w);
    //glClear(GL_COLOR_BUFFER_BIT);
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}

//---------------------------------------------


bool CloseGui()
{
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplSDL2_Shutdown();
    ImGui::DestroyContext();

    Log::write("GUI exited");

    return false;
}

//-------------------------------------------------------------- Initialize SDL


void InitializeWindow(Inputs* inputs)
{

   // SDL_Window* m_window;

    if(SDL_Init( SDL_INIT_EVERYTHING) < 0) 
        Log::error(SDL_GetError());
    else
    {

        Log::write("window initialized");
        // depending on whether SDL_INIT_GAMECONTROLLER is enabled or disabled.. updating to latest version of SDL is recommended!)

        // Decide GL+GLSL versions
        #if defined(IMGUI_IMPL_OPENGL_ES2)
            // GL ES 2.0 + GLSL 100
            const char* glsl_version = "#version 100";
            SDL_GL_SetAttribute(SDL_GL_CONTEXT_FLAGS, 0);
            SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_ES);
            SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 2);
            SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 0);
        #elif defined(__APPLE__)
            // GL 3.2 Core + GLSL 150
            const char* glsl_version = "#version 150";
            SDL_GL_SetAttribute(SDL_GL_CONTEXT_FLAGS, SDL_GL_CONTEXT_FORWARD_COMPATIBLE_FLAG); // Always required on Mac
            SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
            SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
            SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);
        #else
            // GL 3.0 + GLSL 130
            const char* glsl_version = "#version 130";
            SDL_GL_SetAttribute(SDL_GL_CONTEXT_FLAGS, 0);
            SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
            SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
            SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 0);
        #endif  

        // Create window with graphics context

            SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
            SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
            SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE, 8);

            SDL_WindowFlags window_flags = (SDL_WindowFlags)(SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE | SDL_WINDOW_ALLOW_HIGHDPI);
            
            m_window = SDL_CreateWindow("Spaghet about it!", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 720, window_flags);
            m_gl_context = SDL_GL_CreateContext(m_window);
            m_renderer = SDL_CreateRenderer( m_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC );

            SDL_GL_MakeCurrent(m_window, m_gl_context);
            SDL_GL_SetSwapInterval(1); // Enable vsync

            glEnable(GL_TEXTURE_2D);
            glEnable(GL_BLEND);
            //glBlendEquation(GL_FUNC_ADD);
            glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
            glGenTextures(2, TextureID/* &m_inst */); 
   

        //-----------main event stream

            SDL_Event event;

        //------------Init game

            Game* game = new Game(inputs, TextureID);

        //-------- Init GUI

            LaunchGui(glsl_version, inputs, event);

            while (isRunning == true)
            {
                while (SDL_PollEvent(&event))
                {
                    bool res = inputs->pollInput(event, m_window);

                    if (res == false)
                        isRunning = false;

                    GuiPreUpdate(event);
                    game->Update(inputs);
                    RenderGui();
                    SDL_GL_SwapWindow(m_window);  
                }
                        
            }

    //Cleanup

        CloseGui();	

        SDL_DestroyWindow(m_window);
        SDL_GL_DeleteContext(m_gl_context);

        IMG_Quit();
        SDL_Quit();

        delete game;
        delete m_window; 
        delete m_gl_context;   
        
        Log::write("window closed");
    }
}



             

    //SDL_Delay( 2000 );