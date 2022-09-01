#include "../headers/window.h"
#include "../headers/audio.h"
#include "../headers/app.h"

//---------- IMGui


// Gui::Gui(/* SDL_Window* &window, SDL_GLContext &context */)
// {


//     // Load Fonts
//     // - If no fonts are loaded, dear imgui will use the default font. You can also load multiple fonts and use ImGui::PushFont()/PopFont() to select them.
//     // - AddFontFromFileTTF() will return the ImFont* so you can store it if you need to select the font among multiple.
//     // - If the file cannot be loaded, the function will return NULL. Please handle those errors in your application (e.g. use an assertion, or display an error and quit).
//     // - The fonts will be rasterized at a given size (w/ oversampling) and stored into a texture when calling ImFontAtlas::Build()/GetTexDataAsXXXX(), which ImGui_ImplXXXX_NewFrame below will call.
//     // - Read 'docs/FONTS.md' for more instructions and details.
//     // - Remember that in C/C++ if you want to include a backslash \ in a string literal you need to write a double backslash \\ !
//     // io.Fonts->AddFontDefault();
//     // io.Fonts->AddFontFromFileTTF("../../misc/fonts/Roboto-Medium.ttf", 16.0f);
//     // io.Fonts->AddFontFromFileTTF("../../misc/fonts/Cousine-Regular.ttf", 15.0f);
//     // io.Fonts->AddFontFromFileTTF("../../misc/fonts/DroidSans.ttf", 16.0f);
//     // io.Fonts->AddFontFromFileTTF("../../misc/fonts/ProggyTiny.ttf", 10.0f);
//     // ImFont* font = io.Fonts->AddFontFromFileTTF("c:\\Windows\\Fonts\\ArialUni.ttf", 18.0f, NULL, io.Fonts->GetGlyphRangesJapanese());
//     // IM_ASSERT(font != NULL);



//     //     Poll and handle events (inputs, window resize, etc.)
//     //     You can read the io.WantCaptureMouse, io.WantCaptureKeyboard flags to tell if dear imgui wants to use your inputs.
//     //     - When io.WantCaptureMouse is true, do not dispatch mouse input data to your main application, or clear/overwrite your copy of the mouse data.
//     //     - When io.WantCaptureKeyboard is true, do not dispatch keyboard input data to your main application, or clear/overwrite your copy of the keyboard data.
//     //     Generally you may always pass all inputs to dear imgui, and hide them from your application based on those two flags.
       
    
// };


// void Window::LaunchGui(const char* glsl_version, Inputs* inputs, SDL_Event event)
// {

//     // Create window with graphics context

//         SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
//         SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
//         SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE, 8);
//         SDL_WindowFlags window_flags = (SDL_WindowFlags)(SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE | SDL_WINDOW_ALLOW_HIGHDPI);
//         SDL_Window* window = SDL_CreateWindow("Dear ImGui SDL2+OpenGL3 example", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 720, window_flags);
//         SDL_GLContext gl_context = SDL_GL_CreateContext(window);
//         SDL_GL_MakeCurrent(window, gl_context);
//         SDL_GL_SetSwapInterval(1); // Enable vsync

//         IMGUI_CHECKVERSION(); 
//         ImGui::CreateContext();
//         ImGuiIO& io = ImGui::GetIO(); (void)io;
//         io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
//         io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls

//     //Setup Dear ImGui style
//         ImGui::StyleColorsDark();
//         ImGui::StyleColorsClassic();

//     // Setup Platform/Renderer backends
//         ImGui_ImplSDL2_InitForOpenGL(window, gl_context);
//         ImGui_ImplOpenGL3_Init(glsl_version);

//         ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);
//         // Our state
//         bool show_demo_window = true;
//         bool show_another_window = false;
//        // bool isRunning = false;

//         while (m_isRunning == true)
//         {

//         //SDL_Event event;
//         while (SDL_PollEvent(&event))
//         {
//             ImGui_ImplSDL2_ProcessEvent(&event);
//             if (event.type == SDL_QUIT)
//                 m_isRunning = false;
//             if (event.type == SDL_WINDOWEVENT && event.window.event == SDL_WINDOWEVENT_CLOSE && event.window.windowID == SDL_GetWindowID(window))
//                 m_isRunning = false;

//         //poll inputs
//             inputs->pollInput(event, m_isRunning);

//         // Start the Dear ImGui frame
//             ImGui_ImplOpenGL3_NewFrame();
//             ImGui_ImplSDL2_NewFrame();
//             ImGui::NewFrame();

//             // 1. Show the big demo window (Most of the sample code is in ImGui::ShowDemoWindow()! You can browse its code to learn more about Dear ImGui!).

//             if (show_demo_window)
//                 ImGui::ShowDemoWindow(&show_demo_window);

//                 // 2. Show a simple window that we create ourselves. We use a Begin/End pair to created a named window.
//                 {
//                     static float f = 0.0f;
//                     static int counter = 0;

//                     ImGui::Begin("Hello, world!");                          // Create a window called "Hello, world!" and append into it.

//                     ImGui::Text("This is some useful text.");               // Display some text (you can use a format strings too)
//                     ImGui::Checkbox("Demo Window", &show_demo_window);      // Edit bools storing our window open/close state
//                     ImGui::Checkbox("Another Window", &show_another_window);

//                     ImGui::SliderFloat("float", &f, 0.0f, 1.0f);            // Edit 1 float using a slider from 0.0f to 1.0f
//                     ImGui::ColorEdit3("clear color", (float*)&clear_color); // Edit 3 floats representing a color

//                     if (ImGui::Button("Button"))                            // Buttons return true when clicked (most widgets return true when edited/activated)
//                         counter++;
//                     ImGui::SameLine();
//                     ImGui::Text("counter = %d", counter);

//                     ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
//                     ImGui::End();
//                 }

//                 // 3. Show another simple window.
//                 if (show_another_window)
//                 {
//                     ImGui::Begin("Another Window", &show_another_window);   // Pass a pointer to our bool variable (the window will have a closing button that will clear the bool when clicked)
//                     ImGui::Text("Hello from another window!");
//                     if (ImGui::Button("Close Me"))
//                         show_another_window = false;
//                     ImGui::End();
//                 }

//                 // Rendering
//                 ImGui::Render();
//                 glViewport(0, 0, (int)io.DisplaySize.x, (int)io.DisplaySize.y);
//                 glClearColor(clear_color.x * clear_color.w, clear_color.y * clear_color.w, clear_color.z * clear_color.w, clear_color.w);
//                 glClear(GL_COLOR_BUFFER_BIT);
//                 ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
//                     SDL_GL_SwapWindow(window);
//             }
//         }

// // Cleanup
//     ImGui_ImplOpenGL3_Shutdown();
//     ImGui_ImplSDL2_Shutdown();
//     ImGui::DestroyContext();

//     SDL_GL_DeleteContext(gl_context);
//     SDL_DestroyWindow(window);
//     SDL_Quit();

 
// };
